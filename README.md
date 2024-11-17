# push_swap

**push_swap** is an algorithmic project designed to sort a stack of integers using a limited set of operations.

There are 2 stacks named `a` and `b`. The goal is to sort in ascending order numbers into stack `a`.

## Rules

-The stack `a` contains a random amount of negative and/or positive numbers which cannot be duplicated.  

-The stack `b` is empty.  

-Available operations with stacks:

- **sa (swap a):**  
  Swaps the first two elements at the top of stack `a`.  
  Does nothing if there is only one or no elements.

- **sb (swap b):**  
  Swaps the first two elements at the top of stack `b`.  
  Does nothing if there is only one or no elements.

- **ss:**  
  Performs `sa` and `sb` simultaneously.

- **pa (push a):**  
  Takes the first element at the top of stack `b` and move it to the top of stack `a`.  
  Does nothing if stack `b` is empty.

- **pb (push b):**  
  Takes the first element at the top of stack `a` and move it to the top of stack `b`.  
  Does nothing if stack `a` is empty.

- **ra (rotate a):**  
  Shifts all elements of stack `a` upwards by one position.  
  The first element becomes the last.

- **rb (rotate b):**  
  Shifts all elements of stack `b` upwards by one position.  
  The first element becomes the last.

- **rr:**  
  Performs `ra` and `rb` simultaneously.

- **rra (reverse rotate a):**  
  Shifts all elements of stack `a` downwards by one position.  
  The last element becomes the first.

- **rrb (reverse rotate b):**  
  Shifts all elements of stack `b` downwards by one position.  
  The last element becomes the first.

- **rrr:**  
  Performs `rra` and `rrb` simultaneously.


## Usage

### Mandatory part

1.  Clone the repository and compile the program:
   ```bash
   git clone git@github.com:shatilovdr/42-push_swap.git
   cd 42-push_swap
   make
   ```
2.  Run the program with a list of integers as arguments:
   ```bash
   ./push_swap 3 2 5 1 4
   ```
### Bonus: Checker Program
1.  Compile the program:
   ```bash
   make bonus
   ```
2.  Run the program with a list of integers as arguments:
   ```bash
   ./push_swap 3 2 1 | ./checker 3 2 1
   ```
   
