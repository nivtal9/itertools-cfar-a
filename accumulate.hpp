//
// Created by nivtal9 & AVI HAIMOV on 13.6.2020.
//
namespace itertools{
    class combine
    {
    public:
        template <typename T>
        T operator() (T x, T y) const{
            return x + y;
        }
    };
    template <typename container, typename function = combine>
    class accumulate
    {
        function fun;
        container con;
    public:

        accumulate(container c , function f=combine()): con(c), fun(f){
        }
        ///start of iterator
        class iterator {
            typename container::value_type allsum;
            typename container::iterator start_iterator;
            typename container::iterator end_it;
            function func;
        public:
            iterator(typename container::iterator s_it, typename container::iterator e_it, function f):
                    start_iterator(s_it), end_it(e_it), allsum(*s_it), func(f){
            }

            auto operator*() {
                return allsum;
            }

            const iterator operator++(int) {
                iterator t= *(this);
                start_iterator++;
                if(end_it!=start_iterator) {
                    allsum = func(allsum, *start_iterator);
                }
                return t;
            }
            iterator& operator++() {
                start_iterator++;
                if( end_it!=start_iterator ) {
                    allsum = func(allsum, *start_iterator);
                }
                return *(this);
            }

            bool operator !=(const iterator& other) const {
                return other.start_iterator!=start_iterator;
            }
            bool operator ==(const iterator& other) const {
                return other.start_iterator== start_iterator ;
            }
        }; ///end of iterator

        iterator begin() {
            return iterator{con.begin(),con.end(),fun};
        }

        iterator end() {
            return iterator{con.end(),con.end(),fun};
        }
    };
}