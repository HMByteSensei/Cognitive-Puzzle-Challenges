class Solution {
public:
    string simplifyPath(string path) {
        std::stack<char> st{};
        for(int i=0; i<path.length(); ) {
            if(path[i] == '/') {
                while(i<path.length() && path[i] == '/') {
                    i++;
                }
                st.push('/');
            } else if(path[i] == '.') {
                // if(st.top() != '.' && st.top() != '/') {
                //     while(i<path.length() && path[i] != '/') {
                //         st.push(path[i++]);
                //     }
                //     continue;
                // } else {
                int count = 0;
                while(i<path.length() && path[i] == '.') {
                    st.push('.');
                    count++, i++;
                }
                while(i<path.length() && path[i] != '/') {
                    st.push(path[i++]);
                    count = 10;
                }
                if(count <= 2) {
                    while(!st.empty() && st.top() != '/') {
                        st.pop();
                    }
                    if(!st.empty())
                        st.pop();
                    if(count == 2) {
                        while(!st.empty() && st.top() != '/') {
                            st.pop();
                        }
                        if(!st.empty())
                            st.pop();
                    }
                }
            } else {
                while(i<path.length() && path[i] != '/') {
                    st.push(path[i]);
                    i++;
                }
            }
        }

        while(!st.empty() && st.top() == '/') { st.pop(); }
        if(st.empty()) st.push('/');
        std::string res{};
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
