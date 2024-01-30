class Solution {
public:
int evalRPN(vector<string>& tokens) {
    stack<long> st;

    for (int i = 0; i < tokens.size(); i++)
    {
        if(tokens[i] == "+" || tokens[i] == "/" || tokens[i] == "-" || tokens[i] == "*")
        {
            long v1 = st.top(); 
            st.pop();
            long v2 = st.top(); 
            st.pop();

            if(tokens[i] == "+"){
                st.push(v2+v1);
            }
            else if (tokens[i] == "/")
            {
                st.push(v2/v1);
            }
            else if (tokens[i] == "*")
            {
                st.push(v1*v2); 
            }
            else if (tokens[i] == "-")
            {
                st.push(v2-v1);
            }
            
        }
        else {
        st.push(atoi(tokens[i].c_str()));
        }
    } 
return (int)st.top();
} 
};