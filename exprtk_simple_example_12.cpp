/*
 **************************************************************
 *         C++ Mathematical Expression Toolkit Library        *
 *                                                            *
 * Simple Example 12                                          *
 * Author: Arash Partow (1999-2014)                           *
 * URL: http://www.partow.net/programming/exprtk/index.html   *
 *                                                            *
 * Copyright notice:                                          *
 * Free use of the Mathematical Expression Toolkit Library is *
 * permitted under the guidelines and in accordance with the  *
 * most current version of the Common Public License.         *
 * http://www.opensource.org/licenses/cpl1.0.php              *
 *                                                            *
 **************************************************************
*/


#include <cstdio>
#include <string>
#include "exprtk.hpp"


template<typename T>
void bubble_sort()
{
   typedef exprtk::symbol_table<T> symbol_table_t;
   typedef exprtk::expression<T>     expression_t;
   typedef exprtk::parser<T>             parser_t;

   std::string expr_string =
                  " upper_bound := v[];                           "
                  " repeat                                        "
                  "   swapped := false;                           "
                  "   for(i := 0; i < upper_bound; i += 1)        "
                  "   {                                           "
                  "      for(j := i + 1; j < upper_bound; j += 1) "
                  "      {                                        "
                  "         if (v[i] > v[j])                      "
                  "         {                                     "
                  "           temp := v[i];                       "
                  "           v[i] := v[j];                       "
                  "           v[j] := temp;                       "
                  "           swapped := true;                    "
                  "         };                                    "
                  "      };                                       "
                  "   };                                          "
                  "   upper_bound -= 1;                           "
                  " until (not(swapped) or (upper_bound == 0));   ";

   T v[] = { T(2.2), T(1.1), T(5.5), T(4.4), T(3.3) };

   symbol_table_t symbol_table;
   symbol_table.add_vector("v",v);

   expression_t expression;
   expression.register_symbol_table(symbol_table);

   parser_t parser;
   parser.enable_unknown_symbol_resolver();

   parser.compile(expr_string,expression);

   expression.value();
}

int main()
{
   bubble_sort<double>();
   return 0;
}
