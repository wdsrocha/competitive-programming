Really enjoyed solving the qualification round problems. Most of the small tasks could be done with pure simulation, which is kind of cool to motivate beginners. Maybe this is Google's intention, but as this is my first CodeJam, I can't say for sure.

## Problem A

a\_small was pretty much OK. It wasn't hard to see that it could be solved with a BFS on states.

On the other hand, I'm quite upset with a\_large. I had the correct intuitive idea, but couldn't prove the algorithm's correctness. Guess I'll implement it later on.

## Problem B

Fun problem that reminded me a lot of [At Most Twice](https://uva.onlinejudge.org/external/130/13004.pdf). The O(log**N**) solution makes it quite beautiful as well. :)

## Problem C

Spent a lot of time on this one. At first, I tried to see a solution based on segment trees (not implementing it, of course), but hadn't much success. After some time, I gave up and decided to simulate it to secure c\_small. As I should've expected, simulating the process actually helped me find a pattern to build c\_large, which was exactly what I did to solve it.

Sadly, I've used "log2" function from math library (implemented c\_large with python), which gave incorrect results for large values (10^18), causing me to get a Wrong Answer verdict. :(

## Problem D

Not much to say here, I _guess_ it's a bipartite matching, where the board pieces behave **quite** like chess ones (queens for **o**, rooks for **x** and bishops for **+**). Tried to implement it, but I have almost no expertise on this subject, which caused my algorithm to fail even for example test cases. I will come back here once I'm stronger. >:v
