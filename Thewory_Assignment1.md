# CSE 323, Assignment 01

## Q1. Compiler vs Interpreter, Token/Lexeme/Pattern

**Advantages of a compiler over an interpreter**
1. Execution is faster, because the whole program is translated to machine code once.
2. Object code is saved, so there is no need to recompile every run.
3. The source code is not needed at run time, which gives better protection.
4. Whole-program optimization is possible.
5. All errors are reported after analysing the entire program.
6. It uses less memory at run time, because there is no translator in memory.

**Token, Lexeme, Pattern**

| Term | Meaning | Example |
|---|---|---|
| Token | Category or class name given to a group of characters | `id`, `keyword`, `num` |
| Lexeme | The actual character sequence in the source matching a token | `count`, `if`, `60` |
| Pattern | The rule that describes the lexemes of a token | id → letter (letter \| digit)* |

Example: in `int x = 60;`
- `int` → token `keyword`
- `x` → token `id`
- `=` → token `assign_op`
- `60` → token `num`, with pattern digit⁺

---

## Q2. Phases of a compiler

**Expression:** `a = b + c * 60` (a, b, c are float)

| Phase | Output for the expression | Tasks done |
|---|---|---|
| 1. Lexical Analysis | `id1 = id2 + id3 * 60` | Reads characters, groups them into tokens, removes whitespace/comments, builds the symbol table |
| 2. Syntax Analysis | Parse tree: `=(id1, +(id2, *(id3, 60)))` | Checks grammar, builds the parse/syntax tree, reports syntax errors |
| 3. Semantic Analysis | `=(id1, +(id2, *(id3, inttofloat(60))))` | Type checking, type conversion, declaration checking |
| 4. Intermediate Code Generation | `t1 = inttofloat(60)`<br>`t2 = id3 * t1`<br>`t3 = id2 + t2`<br>`id1 = t3` | Generates machine-independent three-address code |
| 5. Code Optimization | `t1 = id3 * 60.0`<br>`id1 = id2 + t1` | Removes redundant code and temporaries, folds constants |
| 6. Code Generation | `LDF R2, id3`<br>`MULF R2, R2, #60.0`<br>`LDF R1, id2`<br>`ADDF R1, R1, R2`<br>`STF id1, R1` | Selects instructions, allocates registers, produces target code |

Symbol table management and error handling work throughout all phases.

---

## Q3. Left Factoring

**Given**
- `<S> → <NP> <VP>`
- `<NP> → <adj> <NP> | <adj> <singular noun>`
- `<VP> → <singular verb> <adverb>`

**Step 1:** Find the common prefix. `<NP>` has two alternatives that both begin with `<adj>`. `<S>` and `<VP>` have a single alternative each, so they need no change.

**Step 2:** Write the rule as `A → αβ₁ | αβ₂`, where α = `<adj>`, β₁ = `<NP>`, β₂ = `<singular noun>`.

**Step 3:** Rewrite it as `A → αA'` and `A' → β₁ | β₂`.

**Left-factored grammar**
```
<S>   → <NP> <VP>
<NP>  → <adj> <NP'>
<NP'> → <NP> | <singular noun>
<VP>  → <singular verb> <adverb>
```

---

## Q4. Left Recursion (LR) vs Left Factoring (LF)

I have taken "LR" as left recursion and "LF" as left factoring.

| | Left Recursion | Left Factoring |
|---|---|---|
| Problem | The leftmost symbol of the RHS is the LHS itself: `A → Aα \| β` | Two or more alternatives share a common prefix: `A → αβ₁ \| αβ₂` |
| Effect on parser | Infinite loop in a top-down parser | Parser cannot decide which production to choose, so it backtracks |
| Solution | Eliminate it: `A → βA'`, `A' → αA' \| ε` | Factor the prefix: `A → αA'`, `A' → β₁ \| β₂` |
| Introduces | A new nonterminal and an ε production | A new nonterminal, no ε needed |
| Purpose | Make the grammar terminate | Make the grammar deterministic (predictive) |

---

## Q5. Why left recursion and common prefix are problems in a top-down parser

**Left recursion:** `E → E + T | T`

To expand E, the parser applies `E → E + T`, which gives E again, and this repeats forever:
E ⇒ E+T ⇒ E+T+T ⇒ …

There is an infinite loop, so the parser never terminates. Fix: `E → T E'`, `E' → + T E' | ε`.

**Common prefix:** `A → ab | ac`

For input `ac`, the parser sees `a` and cannot tell which alternative to use. It tries `A → ab`, fails at `c`, backtracks, and tries `A → ac`. This backtracking wastes time and rules out predictive parsing. Fix: `A → aA'`, `A' → b | c`.

---

## Q6. FIRST and FOLLOW

**Grammar**
```
S → ABC | BCf | abc
A → aA | ε | ASD
B → b | Cd | SDT
C → c | Ae | ε
```
Assumption: D and T are terminals, since they have no production.

**FIRST**
- FIRST(A) ⊇ {a, ε}. Since A is nullable, ASD adds FIRST(S).
- FIRST(C) ⊇ {c, ε}. Ae adds FIRST(A) and `e`.
- FIRST(B) ⊇ {b}. Cd adds FIRST(C) and `d`. SDT adds FIRST(S).
- FIRST(S) = FIRST(A)−ε ∪ FIRST(B) ∪ {a}. (B is not nullable.)

Solving these together, everything collapses to the same set:

| NT | FIRST |
|---|---|
| S | {a, b, c, d, e} |
| A | {a, b, c, d, e, ε} |
| B | {a, b, c, d, e} |
| C | {a, b, c, d, e, ε} |

**FOLLOW**
- FOLLOW(S): `$` (start symbol), and `D` from `ASD` and `SDT`. So {D, $}.
- FOLLOW(A): from ABC, FIRST(BC) = {a..e}. From ASD, FIRST(S). From Ae, `e`. So {a, b, c, d, e}.
- FOLLOW(B): from ABC, FIRST(C)−ε plus FOLLOW(S) (C is nullable). From BCf, FIRST(C)−ε and `f`. So {a, b, c, d, e, f, D, $}.
- FOLLOW(C): from ABC, FOLLOW(S). From BCf, `f`. From Cd, `d`. So {d, f, D, $}.

---

## Q7. LL(1) table

**Modified grammar.** A → ASD is left recursive, so it is eliminated: `A → aA A' | A'` and `A' → S D A' | ε`.

FIRST(A') = {a..e, ε} and FOLLOW(A') = FOLLOW(A) = {a..e}.

**Parsing table**

| | a | b | c | d | e | f | D | $ |
|---|---|---|---|---|---|---|---|---|
| **S** | ABC, BCf, abc | ABC, BCf | ABC, BCf | ABC, BCf | ABC, BCf | | | |
| **A** | aAA', A' | A' | A' | A' | A' | | | |
| **A'** | SDA', ε | SDA', ε | SDA', ε | SDA', ε | SDA', ε | | | |
| **B** | Cd, SDT | b, Cd, SDT | Cd, SDT | Cd, SDT | Cd, SDT | | | |
| **C** | Ae | Ae | c, Ae | Ae, ε | Ae | ε | ε | ε |

**Is it LL(1)? No.**

Many cells hold more than one production, for example M[S, a] = {ABC, BCf, abc}. This happens because:
1. The alternatives of S (and of B) have overlapping FIRST sets, all equal to {a, b, c, d, e}.
2. For A', FIRST(SDA') ∩ FOLLOW(A') = {a..e} ≠ ∅, so the rule for a nullable production is violated.
3. The grammar still has indirect left recursion (S → ABC → BC → SDT…).

Since the table has multiple entries, the grammar is **not LL(1)**.
