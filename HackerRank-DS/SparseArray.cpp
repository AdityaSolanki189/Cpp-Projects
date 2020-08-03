
#include <bits/stdc++.h>


using namespace std;

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    /* 
     # USING MAPS STL #
    map<string,int> metaData;
    for(auto const& str : strings){
        metaData[str]++;
    }
    vector<int> result;
    for(auto const& q : queries){
        result.push_back(metaData[q]);
    } */
    
    /*  
     # USING UNORDERED MAPS STL #
    unordered_map<string,int> map;
    vector<int> result;
    for(auto str : strings){
        map[str]++;
    }

    for(int i=0;i<queries.size();i++){
        if(map.find(queries[i]) != map.end()){
            result.push_back(map[queries[i]]);
        }
        else{
            result.push_back(0);
        }
    }  */

    vector<int> result(queries.size());
    int count=0;
    for(int i=0;i<queries.size();i++)
    {
        count=0;
        for(int j=0;j<strings.size();j++)
        {
            if((queries[i].compare(strings[j])==0))
                count++;
        }
        result[i]=count;
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int strings_count;
    cin >> strings_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> strings(strings_count);

    for (int i = 0; i < strings_count; i++) {
        string strings_item;
        getline(cin, strings_item);

        strings[i] = strings_item;
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<int> res = matchingStrings(strings, queries);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
