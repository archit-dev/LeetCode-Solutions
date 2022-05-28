/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int ans = 0;
        for(Employee * emp : employees){
            if(id==emp->id){
                ans+=emp->importance;
                for(int sub : emp->subordinates){
                    ans+= getImportance(employees,sub);
                }
            }
        }
        return ans;
    }
};