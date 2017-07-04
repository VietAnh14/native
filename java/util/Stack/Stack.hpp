/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef NATIVE_JAVA_STACK_LIST_HPP
#define NATIVE_JAVA_STACK_LIST_HPP

#include <stack>
#include "../function/UnaryOperator/UnaryOperator.hpp"
#include "../Iterator/Iterator.hpp"
#include "../Collection/Collection.hpp"
#include "../Comparator/Comparator.hpp"
#include "../Vector/Vector.hpp"


namespace Java {
    namespace Util {
        template <typename E>
        class Stack {
            // TODO - extend Vector<E>, implement Serializable,
            // Cloneable, Iterable<E>, Collection<E>, List<E>, RandomAccess

		private:

			std::stack<E> original;

        public:

            Stack(){}

            /**
            * Stack empty - check whether the Stack is empty or not
            *
            * @return true only if this stack has no item; false otherwise
            */
            bool empty() {
                return this->original.size() == 0;
            }
            
            /**
             * Stack peek - return the top element
             *
             * @return E
             */
            E peek() {
                return this->original.top();
            }
            
            /**
             * Stack pop - return the top element and remove it
             *
             * @return E
             */
            E pop() {
                E result = this->original.top();
                this->original.pop();
                return result;
            }
            
           /**
            * Stack push - Push new element
            *
            * @param element
            * @return E
            */
            E push(const E &element) {
                this->original.push(element);
                return element;
            }
       
           /**
            * Stack search - search the object in Stack
            *
            * @param object
            * @return the 1-based position from the top, -1 if can not find the object in Stack
            */
            int search(const E &object) {
               //TODO when Vector is done
               //int index = lastIndexOf(Object);
               //if(index>=0) {
               //    return index;
               //}
               //return -1;
            }

			/**
			 * Size of Stack
			 *
			 * @return size of stack
			 */
            int size() {
                return this->original.size();
            }
        };
    }
}

#endif

