- Do you want to find the **majority element** in an array? The majority element is the one that appears more than **half** of the time in the array.
- You can use the **Boyer-Moore voting algorithm**, which is a clever and efficient way to find the majority element in **O(N)** time and **O(1)** space, where N is the size of the array.
- The algorithm works by keeping a variable **votes** that counts the difference between the votes of the current candidate element and the other elements. If votes becomes zero, a new candidate is chosen.
- The algorithm has two main steps:
    - **Find a candidate element** by iterating over the array once and updating votes and candidate as you go.
    - **Verify if the candidate element is indeed the majority element** by iterating over the array again and counting its occurrences.
- To see how the algorithm works, let's do a dry run for an example array {1, 5, 5, 1, 1, 1}:

| Element | Votes | Candidate |
|---------|-------|-----------|
| 1       | 0     | -1        |
| 5       | 1     | 5         |
| 5       | 2     | 5         |
| 1       | 1     | 5         |
| 1       | 0     | -1        |
| 1       | 1     | 1         |

The final candidate is 1, which is also the majority element..
