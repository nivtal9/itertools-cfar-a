//
// Created by nivtal9 & AVI HAIMOV on 13.6.2020.
//

namespace itertools{
    template <typename con, typename bucket>
    class filterfalse
    {
    private:
        bucket buck;
        con cond;
    public:
        filterfalse(con co, bucket c): buck(c), cond(co){}

        class iterator {
            con condition;
            typename bucket::iterator start_it;
            typename bucket::iterator end_it;
        public:
            iterator(typename bucket::iterator start_iterator, typename bucket::iterator end_iterator, con co):
                    start_it(start_iterator), end_it(end_iterator), condition(co){

            }
            iterator& operator++() {
                do {
                    start_it++;
                }
                while(start_it!= end_it && condition(*start_it));
                return *this;
            }
            auto operator*() {
                if (condition(*start_it)) {
                ++(*this);
                }
                return *(start_it);
            }

            bool operator!=(const iterator& other) const {
                return start_it != other.start_it;
            }
            bool operator==(const iterator& other) const {
                return start_it == other.start_it;
            }
        };

        iterator begin() {
            return iterator{buck.begin(), buck.end(), cond};
        }

        iterator end() {
            return iterator{buck.end(), buck.end(), cond};
        }
    };
}