# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?
-- an invented word to highlight ridiculousness of medical terms-- means an imflammation of lungs by ash

TODO

## According to its man page, what does `getrusage` do?
-- show/return recource usage and errors

TODO

## Per that same man page, how many members are in a variable of type `struct rusage`?
<<<<<<< HEAD
## one
=======
one
>>>>>>> 20b1d308ea723dc9f3e83b82e1dfd63976be1cbf

TODO

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?
-- it prevents redundancy and saves memory

TODO

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

TODO

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?
-- words with apostrophon might not be recognized

TODO

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?
## So they are not changed by accident


TODO
