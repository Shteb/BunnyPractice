# BunnyPractice
A simple bunny ecosystem sim that collapses from infection.

### High-Level Logic
Simplified, this program takes the following logical steps per loop:
1. Iterate through all living bunnies.
2. Age up all bunnies, making note of which will die this cycle.
3. If a healthy male age 2 or above is present, make note for birthing new bunnies later.
4. For each healthy female age 2 or above, note its colour down to pass down to new bunnies later.
5. Keep count of the number of infected for further infecting later.
6. Randomly select n bunnies to be infected where n is the number gathered in the previous step, and infect them.
7. Birth new bunnies corresponding to the colours stored in step 4.
8. Kill all bunnies as noted in step 2.
9. Make a population check and cull half if greater than 1000.
10. Repeat.
