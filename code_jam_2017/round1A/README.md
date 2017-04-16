Unfortunately, I had to leave the contest after the first hour, so I couldn't do/try much.

### Problem A
This task was rather easy, but I wasn't clever enough to come up with a simpler solution and ended up simulating the whole process.

Basically, the idea behind my code is to fill the left and right side for every letter in my grid. This asserts that every row which contains at least one letter will be completely filled with the selected letter. e.g., row "??A??B?C" might become "AAAAABBC".

Of course, this isn't enough to fill the whole grid, as every empty row will remain empty. To solve this, we now need to fill up and down for a given "letter block". It's easy to see that after executing this step for every letter block, our grid will be completely filled.
