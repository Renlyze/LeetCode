
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ms = matrix.size();
        int mi = matrix[0].size();

        for (int rows = 0; rows < ms; rows++){
            for (int columns = 1; columns < mi; columns++){
                matrix[rows][columns] += matrix[rows][columns - 1];
            }
        }

        int currentcount = 0;

        for (int count1 = 0; count1 < mi; count1++){
            for (int count2 = count1; count2 < mi; count2++){
                std::unordered_map<int,int> map;
                map[0] = 1;
                int sum = 0;

                for (int rows = 0; rows < ms; rows++){
                    sum += matrix[rows][count2] - (count1 > 0 ? matrix[rows][count1 - 1] : 0);
                    currentcount += map[sum - target];
                    map [sum]++;
                }
            }
        }
        return currentcount;
    }
};