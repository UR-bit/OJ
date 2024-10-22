class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int m = num1.size();
        int n = num2.size();
        vector<int> result(m + n, 0);
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j; 
                int p2 = i + j + 1; 
                int sum = mul + result[p2];
                result[p2] = sum % 10; 
                result[p1] += sum / 10; 
            }
        }
        string product;
        for (int num : result) {
            if (!(product.empty() && num == 0)) { 
                product.push_back(num + '0');
            }
        }
        return product;
    }
};
