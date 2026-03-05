# Developer Log

## Entry 1
**Date:** 2026-02-26
**Entry Type:** Engineering Decision
**Task worked on:** Project Setup
**Issue or decision:** Choice of Data Structure.
**Decision:** I am going to be using a Circular Linked List rather than std::list or std::vector.
**Reasoning:**  Because im going to be manual manipulating pointers to simulate the "ring" of a board game, a circular linked list would work best.

---

### Entry 2
**Date:** 2026-03-02  
**Entry Type:** Edge Case / Testing Entry  
**Task worked on:** Implementing `addMany` and enforcing board capacity.  
**Issue or decision:** Ensuring the board won't add more than 40 spaces without breaking the circular link.  
**Error message / symptom (if applicable):** N/A
**What I tried:** I tested the addMany function by trying to pass 45 dummy spaces to see if the game would break. 
**Fix / resolution (or final decision):** The addSpace method correctly returned false on the 41st space. The addMany loop caught this false return, stopped iterating, and returned 40. The circular pointers remained fully intact additionally.

---

### Entry 3
**Date:** 2026-03-04  
**Entry Type:** Bug Fix / Edge Case  
**Task worked on:** `printFromPlayer` display logic.  
**Issue or decision:** Stopping infinite loops when printing the board.  
**Error message / symptom:** Endless console spam. Program hanging.  
**What I tried:** Checking for nullptr to end the loop but that didn't end up working since the tail always points back to head. No nulls exist once the board is built.  
**Fix / resolution:** Switched to a strict for loop instead. Relying entirely on the count parameter to stop. Also added a quick if (playerNode == nullptr) at the very beginning. Prevents crashing if called on an empty board.

### Entry 4
**Date:** 2026-03-05  
**Entry Type:** Bug Fix / Edge Case 
**Task worked on:** removeByName function  
**Issue or decision:** What happens if the player is standing on the space being deleted?  
**Error message / symptom:** Dangling pointer. Game crashes when trying to move the player after their space is gone.  
**What I tried:** Originally just deleted the node and patched the head/tail links. Need to deal with the player cursor.
**Fix / resolution:** Added a check before calling delete. If playerNode == curr, bump the player forward one space.

## Entry 5
**Date:** **Entry Type:** **Task worked on:** **Issue or decision:** **Error message / symptom:** **What I tried:** **Fix / resolution:** ---
*(Add more entries as you progress)*
