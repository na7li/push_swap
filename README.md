Hello guys
in this page I'll provide a step by step guide covered all what you'll need to learn and do to create your push_swap program an get it work 100% with no issues.

## 1. what you'll need to learn before start coding
1. Singly Linked list
2. Data structer
3. time complexity
4. memory/space complexity
5. different sorting algorithms (pros and cons of each one)

## 2. Prepare your workspace
1. Mandatory directory
2. Bonus directory
3. Makefile
4. Headerfile (.h)
5. libft if you want (for me I just needed atol (cutomized ft_atoi to handle overflow) for mandatory and get_next_line for bonus)

you can organize it as you want;

## 3. Parsing inputs
The first thing you want to do is to start parsing the inputs.
what i mean is you want to accept as input just integers INT e.g.(21 02 000000000000000000008 -8 +6 -0 +0 )
excepte that you'll return Error\n
here are the cases you want to handle in pasing
* duplicates (we'll handle it in step 4): -0 +0 || 12 54 8 65 8
* emply arguments: "" "       "
* Also: "--56" "++6541" "-+987" "+-66" "6-" "5-4" "614gfgh" "f 654"

What to accept as input: "   21" "3 2  " "  -21  54  " " 00000000000000000000000000000000005 +333"

it's easy, you can do it;
examine empty arguments and unwanted chars first
then check -- ++ 8-+ cases
if input is valide then you can valiate the numbers with ft_atol.

ft_atol funcsion will help you to handle this zeros case (00000000000000000000000000000000005), then if the final number is not in INT rang (long..) then you return MAX_LONG to tell the called function that this number is not what we want and we free all and return NULL;
anyways i want you to do the parsing and enjoying it;

Now when you're done, you can go to the next step.
Remember you have not checked the double yet, we'll do that in the next step;

## 4. Create your stuck
I've used singly linked list which I learned on bonus of libft project. actualy no need to use doubly / cercle linked list. singly is quite enough.
now you'll need to check doubles. and to that you'll need to enter the numbers you got from arguments to the stack linked list. so you'll get a function that creates nodes and addback function to craete your stack_a.
Then every time you get a number you'll check if it's already existing in the stuck_a. and if yes you'll free all and return Error\n if not you'll add it to the end of the stack_a;
when done you'll go to the next step

## 5. Check sorting
when you done the previous step you'll check the if the numbers you entered are sorted. if sorted you'll free all and exit.
if not sorted you'll create a function to sort the stuck.

before sorting the stuck you'll need to calculate its lenth inorder to decide which algo you'll use.

## 6. Soring algorithms I used
### 6.0. swap stack_a
swapstack_a if the two numbers are not sorted

### 6.1. Sort_three
in this function I handle different cases to sort a stuck with three numbers (len == 3).
void				sort_three(t_stack **a);
it's easy to emplement. do it yor self and enjoy.

### 6.2. sort_five
this function will sort 4 and 5 digits.
the idea is to push the min value to stack_b (if len == 5 you push again the minimum value to stack_b)
then you call sort_three function to sort the remain three numbers
then you pa push from stack_b to stack_a, they will be sorted automatically.
and you free all and exit;

### 6.3. sort <= 100
