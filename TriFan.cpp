/**
 * Instructor's solution for A5 in ECE 3400, Fall 2020.
 * @author Andrew Vardy
 */
#include "TriFan.h"

namespace A6 {

TriFan::TriFan(const PolarVec vertexArray[], int nVertices)
    : m_pVertices{ new PolarVec[nVertices] }
    , m_nVertices{ nVertices }
{
    if (m_nVertices < 2)
        throw TriFanConstructionException{};

    // Copying from input array
    for (int i=0; i<nVertices; i++)
        m_pVertices[i] = vertexArray[i];
}

TriFan::TriFan(const TriFan& other)
    : m_pVertices{ new PolarVec[other.m_nVertices] }
    , m_nVertices{ other.m_nVertices }
{
    for (int i=0; i<m_nVertices; i++)
        m_pVertices[i] = other.m_pVertices[i];
}

TriFan& TriFan::operator=(const TriFan& other)
{
    if (this != &other) {
        delete[] m_pVertices;
        m_pVertices = new PolarVec[other.m_nVertices];
        m_nVertices = other.m_nVertices;
        for (int i=0; i<m_nVertices; i++)
            m_pVertices[i] = other.m_pVertices[i];
    }
    return *this;
}

TriFan::~TriFan()
{
    delete[] m_pVertices;
}

void TriFan::split1(TriFan*& pieceOne, TriFan*& pieceTwo) const
{
    split2(this, pieceOne, pieceTwo);
}

void split2(const TriFan *input, TriFan*& pieceOne, TriFan*& pieceTwo)
{
    if (input->m_nVertices <= 2) {
        pieceOne = nullptr;
        pieceTwo = nullptr;
        throw TriFanSplitException{};
    }

    int n = input->m_nVertices;
    int n_2 = n / 2;  // Note that this is integer division.
    int nFirst = n_2 + 1;
    int nSecond = n - n_2;

    PolarVec* firstHalf = new PolarVec[nFirst];
    PolarVec* secondHalf = new PolarVec[nSecond];

    for (int i=0; i <= n_2; i++)
        firstHalf[i] = input->m_pVertices[i];

    for (int i=n_2; i < n; i++)
        secondHalf[i - n_2] = input->m_pVertices[i];

    pieceOne = new TriFan(firstHalf, nFirst);
    pieceTwo = new TriFan(secondHalf, nSecond);

    delete[] firstHalf;
    delete[] secondHalf;
}

ostream& operator<<(ostream& os, TriFan t) {
    os << "nVertices: " << t.m_nVertices;
    os << ", [";
    for (int i=0; i<t.m_nVertices; i++) {
        os << t.m_pVertices[i];
        if (i <t.m_nVertices - 1) os << ", ";
    }
    os << "]";
    return os;
}

bool operator==(const TriFan &a, const TriFan &b)
{
    if (a.m_nVertices != b.m_nVertices)
        return false;

    for (int i=0; i<a.m_nVertices; i++)
        if (a.m_pVertices[i] != b.m_pVertices[i])
            return false;
    return true;
}
 
bool operator!=(const TriFan &a, const TriFan &b)
{
    return !(a == b);
}

};