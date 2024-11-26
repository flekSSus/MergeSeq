#include<iostream>
#include<fstream>
#include<queue>


int main()
{
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    
    int num_of_seq(0);
    int sz(0);

    in>>num_of_seq>>sz;

    std::vector< std::vector<int> > seq_matrix(num_of_seq, std::vector<int>(sz,0));
    std::priority_queue< std::tuple<int, int ,int>,std::vector<std::tuple<int,int,int>>, std::greater<std::tuple<int,int,int>> > heap;

    for(int i(0);i<num_of_seq;++i)
        for(int j(0);j<sz;++j)
            in>>seq_matrix[i][j];

    for(int i(0);i<num_of_seq;++i)
    {
        //tuple(el,seq,index)
        heap.push(std::make_tuple(seq_matrix[i][0],i,0));
    }

    auto topTuple(heap.top());
    while(!heap.empty())
    {
        out<<std::get<0>(topTuple)<<" ";
        heap.pop();
        if(std::get<2>(topTuple)+1 < sz)
        {
            auto newTuple(std::make_tuple(seq_matrix[std::get<1>(topTuple)][std::get<2>(topTuple)+1],std::get<1>(topTuple),std::get<2>(topTuple)+1));
            heap.push(newTuple);
        }
        topTuple=heap.top();
    }
    
}
