# Developer Log

## Entry 1
**Date:** 2026-02-26
**Entry Type:** Engineering Decision
**Task worked on:** Project Setup
**Issue or decision:** Choice of Data Structure.
**Decision:** I am going to be using a Circular Linked List rather than `std::list` or `std::vector`.
**Reasoning:**  Because im going to be manual manipulating pointers to simulate the "ring" of a board game, a circular linked list would work best.

---

### Entry 2
**Date:** 2026-03-02  
**Entry Type:** Edge Case / Testing Entry  
**Task worked on:** Implementing `addMany` and enforcing board capacity.  
**Issue or decision:** Ensuring the board won't add more than 40 spaces without breaking the circular link.  
**Error message / symptom (if applicable):** N/A
**What I tried:** I tested the `addMany` function by trying to pass 45 dummy spaces to see if the game would break. 
**Fix / resolution (or final decision):** The `addSpace` method correctly returned `false` on the 41st space. The `addMany` loop caught this `false` return, stopped iterating, and returned `40`. The circular pointers remained fully intact additionally.

---

## Entry 3
**Date:** **Entry Type:** **Task worked on:** **Issue or decision:** **Error message / symptom:** **What I tried:** **Fix / resolution:** ---
*(Add more entries as you progress)*