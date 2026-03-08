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
**Entry Type:** Edge Case
**Task worked on:** Enforcing board capacity for addMany.  
**Issue or decision:** Ensuring the board won't add more than 40 spaces without breaking the circular link.  
**Error message / symptom (if applicable):** N/A
**What I tried:** added a condition to prevent addMany from passing 40 spaces to see if the game would break. 
**Fix / resolution (or final decision):** The addSpace method will return false on the 41st space. The addMany loop will catch this for any amount of spaces over 40, stop iterating, and return 40.

---

### Entry 3
**Date:** 2026-03-04  
**Entry Type:** Bug Fix / Edge Case  
**Task worked on:** printFromPlayer display logic.  
**Issue or decision:** Stopping infinite loops when printing the board.  
**Error message / symptom:** Endless console spam. 
**What I tried:** Checked for nullptr to end the loop but that didn't end up working since the tail always points back to head. No nulls will exist once the board is built.  
**Fix / resolution:** Switched to a strict for loop instead, relying entirely on the count parameter to stop it. Also added a quick if (playerNode == nullptr) at the very beginning, which will prevent crashing if called on an empty board.

---

### Entry 4
**Date:** 2026-03-05  
**Entry Type:** Bug Fix / Edge Case 
**Task worked on:** removeByName function  
**Issue or decision:** What happens if the player is standing on the space being deleted 
**Error message / symptom:** dangling pointer, game crashes when trying to move the player after their space is gone.  
**What I tried:** Originally just deleted the node and patched the head/tail links, but I need to deal with the player cursor.
**Fix / resolution:** Added a check before calling delete. If playerNode == curr, bump the player forward one space.

---

### Entry 5
**Date:** 2026-03-06  
**Entry Type:** Engineering Decision  
**Task worked on:** findByColor function.  
**Issue or decision:** return vector with results or print results (as stated in the rubric).  
**Decision:** Chose to print the names directly inside the loop. Used a simple for loop up to nodeCount.  
**Reasoning:** Much simpler than dealing with vectors. The loop ensures we check every node exactly one time.

---

### Entry 6
**Date:** 2026-03-07  
**Entry Type:** Engineering Decision / Bug Fix  
**Task worked on:** cleanup issues with clear.  
**Issue or decision:** how to delete a circular list without infinite loops or crashing.  
**Error message / symptom:** Errors when deleting a node that is still pointed to by the tail.  
**What I tried:** thought about using a for loop with nodeCount again, but I realized there was a simpler way to do it.  
**Fix / resolution:** I set tailNode->nextNode = nullptr. this breaks the circle for the linked list, and turns it back into a normal linked list. Then I used a while loop to delete each node safely.