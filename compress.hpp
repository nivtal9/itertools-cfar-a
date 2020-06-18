//
// Created by nivtal9 & AVI HAIMOV on 13.6.2020.
//
namespace itertools{
    template <typename bucket, typename bucket2 >
    class compress
    {
        bucket con;
        bucket2 con_flag;
    public:
        compress(bucket cont , bucket2 fun): con(cont), con_flag(fun){

        }

        class iterator {
            typename bucket::iterator start_it;
            typename bucket2::iterator startF_it;
            typename bucket::iterator end_it;
            typename bucket2::iterator endF_it;
        public:
            iterator(typename bucket::iterator start_iterator, typename bucket::iterator end_iterator,
                    typename bucket2::iterator startF_iterator, typename bucket2::iterator endF_iterator):
                    start_it(start_iterator), end_it(end_iterator), startF_it(startF_iterator), endF_it(endF_iterator){}

            auto operator*() {
                if(!*startF_it) {
                    ++(*this);
                }
                return *start_it;
            }

            const iterator operator++(int) {
                iterator t= *(this);
                ++(*this);
                return t;
            }
            iterator& operator++() {
                do {
                    start_it++;
                    startF_it++;
                }
                while(start_it!= end_it && !(*startF_it));
                return *(this);
            }
            bool operator!=(const iterator& other) const {
                return (start_it != other.start_it) || (startF_it != other.startF_it);
            }
            bool operator==(const iterator& other) const {
                return (start_it == other.start_it) && (startF_it == other.startF_it);
            }
        };

        iterator begin() {
            return iterator{con.begin(), con.end(), con_flag.begin(), con_flag.end()};
        }

        iterator end() {
            return iterator{con.end(), con.end(), con_flag.end(), con_flag.end()};
        }
    };
}