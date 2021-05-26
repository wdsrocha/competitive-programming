# Competitive Programming

Some of my solutions to competitive programming problems.

## Submission downloader script

This repository also have an script to download multiple submissions from URI at
once.

First, create a file named `submissions.queue.txt` in the root directory. This
file should contain a list of submission ids like this:

```
3614517
6398988
14804587
```

This queue will be processed during the execution of the script, removing each
submission after downloading it's code.

Now, [install yarn](https://yarnpkg.com/) if you haven't already.

Install the required dependencies by running `yarn install` on the root
directory.

Run the script with `yarn start your@email.com yourPassword`, where
`your@email.com` and `yourPassword` is your URI e-mail and password,
respectively.

The command above will start downloading files and putting them into the `uri/`
directory.

Currently, if a submission is already downloaded, the script will interrupt the
execution. You'll need to remove this submission from the
`submissions.queue.txt` file manually and run the script again.

If the script crashes, you might want to re-run it, and it will restart from
where it stopped.
