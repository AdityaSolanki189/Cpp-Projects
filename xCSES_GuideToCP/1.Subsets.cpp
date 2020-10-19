/* Our first application of recursion is generating all subsets of a set of n elements. For example, the subsets of {1, 2, 3} are ∅, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, and {1, 2, 3}. The following recursive function search can be used to generate the subsets. The function maintains a vector that will contain the elements of each subset. The search begins when the function is called with the parameter 1*/
//Using Recursive Aglorithm

/* Approach: The idea is simple, that if there are n number of elements inside an array, there are two choices for every element. Either include that element in the subset or do not include it.
Using the above idea form a recursive solution to the problem.

Algorithm:
    1. Create a recursive function that takes the following parameters, input array, the current index, the output array or current subset, if all the subsets needs to be stored then a vector of array is needed, if the subsets need to be printed only then this space can be ignored.
    2. if the current index is equal to the size of the array, then print the subset or output array or insert the output array into the vector of arrays (or vectors) and return.
    3. There are exactly two choices for very index.
    4. Ignore the current element and call the recursive function with the current subset and next index, i.e i + 1.
    5. Insert the current element in the subset and call the recursive function with the current subset and next index, i.e i + 1. 
*/

void search(int k)
{
    if (k == n + 1)
    {
        // process subset
    }
    else
    {
        // include k in the subset
        subset.push_back(k);
        search(k + 1);
        subset.pop_back();
        // don’t include k in the subset
        search(k + 1);
    }
}