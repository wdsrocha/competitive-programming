/* eslint-disable no-undef */
const puppeteer = require("puppeteer");
const fs = require("fs");
const chalk = require("chalk");
const { exit } = require("process");

const args = process.argv.slice(2);
const [email, password] = args;

if (!email || !password) {
  console.log(
    "Pass your email and password as arguments. Example: `yarn start foo@bar.com foobarqux123`"
  );
  exit();
}

const BASE_URL = "https://www.urionlinejudge.com.br/judge/pt";
const routes = {
  login: () => `${BASE_URL}/login`,
  submission: (id) => `${BASE_URL}/runs/code/${id}`,
};

const SUBMISSION_QUEUE_PATH = "./submissions.queue.txt";

const submissionQueueFile = fs.readFileSync(SUBMISSION_QUEUE_PATH);
const submissionQueue = submissionQueueFile.toString().split("\n");
console.log("Queued submissions:");
console.log(submissionQueue);

function clickAndWaitForNavigation(page, selector, clickOptions, waitOptions) {
  return Promise.all([
    page.waitForNavigation(waitOptions),
    page.click(selector, clickOptions),
  ]).then((value) => value[0]);
}

(async () => {
  const browser = await puppeteer.launch();
  const page = (await browser.pages())[0];
  await page.setViewport({ width: 1366, height: 768 });
  //   page.on("console", (msg) => console.log("PAGE LOG:", msg.text()));

  // login
  await page.goto(routes.login());
  await page.type("#email", email);
  await page.type("#password", password);
  await page.click("#remember-me");
  await clickAndWaitForNavigation(page, "input.send-green");

  // eslint-disable-next-line no-constant-condition
  while (true) {
    const submission = submissionQueue.pop();
    if (submission === undefined || submission === "") {
      break;
    }

    const existingFiles = fs.readdirSync("./uri");
    const submissionAlreadyExists = existingFiles.some((filename) =>
      filename.includes(submission)
    );
    if (submissionAlreadyExists) {
      console.log(
        `Skipping submission: submission #${submission} already exists`
      );
      break;
    }

    console.log(`Processing submission #${submission}...`);

    await page.goto(routes.submission(submission));
    const { title, code } = await page.evaluate(() => {
      const titleElement = document.querySelector(
        "#information-code > dl > dd:nth-child(2) > a"
      );
      const title = titleElement && titleElement.innerText;

      // eslint-disable-next-line no-undef
      const codeElement = document.querySelector(".ace_text-layer");
      let code = codeElement && codeElement.innerText;

      if (code) {
        const dateElement = document.querySelector(
          "#information-code > dl > dd:nth-child(16)"
        );
        const date = dateElement && dateElement.innerText;
        code = `// Submitted at ${date}\n${code}`;
      }

      return {
        title,
        code,
      };
    });

    if (!title || !code) {
      console.log("Skipping submission: couldn't get sufficient data");
      break;
    }

    const path = `./uri/${title} - #${submission}.cpp`;
    fs.writeFileSync(path, code);
    console.log(`Created ${chalk.green(path)} ✅`);

    fs.writeFileSync(SUBMISSION_QUEUE_PATH, submissionQueue.join("\n"));
  }

  await browser.close();
})();
