### What is this?!
this code and configuration shows how a weak C library can be a bullet to your foot and change memory data collaturally!

Our weak library changes x and y variables together without any error or warning, that shows we should have a very good understanding about memory and it's L/R Values!

### What happens in memory?


First, we have x and y, each of which uses 1B of memory as a character.

| L Val | R Val |
|:-----:|:-----:|
| ...   | ...   |
|-------|-------|
| &8000 | 0x61  |
|-------|-------|
| &8001 | 0x62  |
|-------|-------|
| &8002 | 0x00  |
| &8003 | 0x00  |
| ...   | ...   |

After executing f() we actually assign x=0x00003B29.
That affects 4B of memory, and also written on y, as you can see the C linker doesn't care!

| L Val | R Val |
|:-----:|:-----:|
| ...   | ...   |
|-------|-------|
| &8000 | 0x29  |
| &8001 | 0x3b  |
| &8002 | 0x00  |
| &8003 | 0x00  |
|-------|-------|
| ...   | ...   |