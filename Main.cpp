#include<iostream>
#include<vector>

void printAdjSum(const std::vector<int>& nums);
void printOuterToInnerSum(const std::vector<int>& nums);


int main()
{
	int num;
	std::vector<int> nums;

	std::cout << "Please enter a series of space seperated number, press Rtn then ctrl + z to exit.\n";

	// ctrl + z to manually tell the loop it is EOF, this will exit the loop.
	while (std::cin >> num)
	{
		nums.push_back(num);
	}

	printAdjSum(nums);

	std::cout << '\n';

	printOuterToInnerSum(nums);

	return 0;
}

void printAdjSum(const std::vector<int>& nums)
{
	int sum = 0;

	for (decltype(nums.size()) i = 1; i < nums.size(); ++i)
	{
		sum = nums[i] + nums[i - 1];
		std::cout << sum << ", ";
		sum = 0;
	}
}

void printOuterToInnerSum(const std::vector<int>& nums)
{
	int sum = 0;

	for (decltype(nums.size()) i = 0; i < nums.size(); ++i)
	{
		if (nums.size() % 2 == 0)
		{
			if (i == nums.size() / 2)
			{
				break;
			}
			else
			{
				sum = nums[i] + nums[(nums.size() - 1) - i];
				std::cout << sum << ", ";
				sum = 0;
			}
		}
		else
		{
			if (i == (nums.size() / 2) + 1)
			{
				break;
			}
			else
			{
				sum = nums[i] + nums[(nums.size() - 1) - i];
				std::cout << sum << ", ";
				sum = 0;
			}
		}		
	}
}