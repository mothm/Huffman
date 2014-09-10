#ifndef HUFFMAN_H
#define HUFFMAN_H

class HuffmanNode
{
private:
    HuffmanNode &left;
    HuffmanNode &right;
    int count;
    char *letter;

public:
    HuffmanNode(HuffmanNode &left, HuffmanNode &right, int count,
                char *letter = 0)
    {
        this->left   = left;
        this->right  = right;
        this->count  = count;
        this->letter = letter;
    }

    HuffmanNode(int count, char *letter)
    {
        this->count  = count;
        this->letter = letter;
        left  = 0;
        right = 0;
    }
    HuffmanNode* getLeft() { return left }
    HuffmanNode* getRight() { return right }
    char getLetter() { return *letter }
    int getCount() { return count }
};

#endif
