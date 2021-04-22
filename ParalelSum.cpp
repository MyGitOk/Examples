#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

std::string ParallelSums(int arr[], unsigned int arrLength)
{
    std::string result("-1");

    if(arr && arrLength && !(arrLength % 2)) // if array is valid AND array length is valid AND array length is a multiple of 2
    {
        int summ = 0;
        std::vector<int> sorted_vec(&arr[0], &arr[arrLength]); // copy source array to the vector
        std::sort(sorted_vec.begin(), sorted_vec.end(), std::greater<int>()); // sort vector sort the vector in descending order (from biggest to less)

        for(auto x : sorted_vec)
        {
            summ += x; // sum up all the elements
        }

        if(!(summ % 2)) // if sum is a multiple of 2 than continue
        {
            int lsumm = 0; // sum of the left half of array
            int rsumm = 0;
            std::set<int> left; // set beacouse it sort automaticly
            std::set<int> right;

            for(auto x : sorted_vec)
            {
                if((lsumm <= rsumm) && ((lsumm + x) <= (summ / 2)))
                {
                    left.insert(x);
                    lsumm += x;
                }
                else
                {
                    right.insert(x);
                    rsumm += x;
                }
            }

            if(lsumm == rsumm)
            {
                result.clear();

                for(auto l_x : left) // write to the result left part of half array
                {
                    if(!result.empty())
                    {
                        result += ", " + std::to_string(l_x);
                    }
                    else // first element without ", "
                    {
                        result += std::to_string(l_x);
                    }
                }

                for(auto r_x : right) // write to the result right part of half array
                {
                    result += ", " + std::to_string(r_x);
                }
            }
        }
    }

    return result;
}

int main()
{
    const unsigned int size = 8;
    int arr[size] = {16,22,35,8,20,1,21,11};
//    const unsigned int size = 4;
//    int arr[size] = {1,2,1,5};

    std::cout << ParallelSums(arr, size) << std::endl; // 1, 11, 20, 35, 8, 16, 21, 22
    return 0;
}
