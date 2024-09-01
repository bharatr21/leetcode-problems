/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode *p1 = poly1, *p2 = poly2;
        PolyNode* dummy = new PolyNode();
        PolyNode* res = dummy;
        while(p1 || p2) {
            while(p1 && p2) {
                if(p1->power > p2->power) {
                    res->next = new PolyNode(p1->coefficient, p1->power);
                    p1 = p1->next;
                }
                else if(p2->power > p1->power) {
                    res->next = new PolyNode(p2->coefficient, p2->power);
                    p2 = p2->next;
                }
                else {
                    if(p1->coefficient + p2->coefficient != 0)
                        res->next = new PolyNode(p1->coefficient + p2->coefficient, p1->power);
                    p1 = p1->next;
                    p2 = p2->next;
                }
                if(res->next) res = res->next;
            }
            while(p1) {
                res->next = new PolyNode(p1->coefficient, p1->power);
                p1 = p1->next;
                res = res->next;
            }
            while(p2) {
                res->next = new PolyNode(p2->coefficient, p2->power);
                p2 = p2->next;
                res = res->next;
            }
        }
        return dummy->next;
    }
};