#include <iostream>
#include "Player.h"
#include "Arena.h"
#include "globals.h"
using namespace std;


///////////////////////////////////////////////////////////////////////////
//  Player implementations
///////////////////////////////////////////////////////////////////////////


Player::Player(Arena* ap, int r, int c)
{
    if (ap == nullptr)
    {
        cout << "***** The player must be in some Arena!" << endl;
        exit(1);
    }
    if (r < 1  ||  r > ap->rows()  ||  c < 1  ||  c > ap->cols())
    {
        cout << "**** Player created with invalid coordinates (" << r
             << "," << c << ")!" << endl;
        exit(1);
    }
    m_arena = ap;
    m_row = r;
    m_col = c;
    m_age = 0;
    m_dead = false;
}

int Player::row() const
{
    return m_row;
}

int Player::col() const
{
    return m_col;
}

int Player::age() const
{
    return m_age;
}

string Player::takeComputerChosenTurn()
{
    if(m_arena->nRobotsAt(m_row,m_col+1)==0 && m_arena->nRobotsAt(m_row,m_col-1)==0 && m_arena->nRobotsAt(m_row+1,m_col)== 0 && m_arena->nRobotsAt(m_row-1,m_col)==0) {//Not surrounded
        if (m_arena->nRobotsAt(m_row, m_col + 2) > 0 || m_arena->nRobotsAt(m_row, m_col - 2) > 0 || m_arena->nRobotsAt(m_row + 2, m_col) > 0 || m_arena->nRobotsAt(m_row - 2, m_col) > 0){
            //checks if a robot is 2 in any direction
            if (m_arena->nRobotsAt(m_row - 2, m_col) > 0) {//shoots up
                bool shot = shoot(UP);
                if (shot == true)
                    return "Shot and hit!";
                return "Shot and missed!";
            }
            if (m_arena->nRobotsAt(m_row + 2, m_col) > 0) {//shoots down
                bool shot = shoot(DOWN);
                if (shot == true)
                    return "Shot and hit!";
                return "Shot and missed!";
            }
            if (m_arena->nRobotsAt(m_row, m_col - 2) > 0) {//shoots left
                bool shot = shoot(LEFT);
                if (shot == true)
                    return "Shot and hit!";
                return "Shot and missed!";
            }
            if (m_arena->nRobotsAt(m_row, m_col + 2) > 0) {//shoots right
                bool shot = shoot(RIGHT);
                if (shot == true)
                    return "Shot and hit!";
                return "Shot and missed!";
            }
        }
        stand();
        return "Stood.";
    }
    if (m_arena->nRobotsAt(m_row - 1, m_col) == 0 && m_row > 1) {//Up is safe to move
        move(UP);
        return "Moved.";
    }
    if (m_arena->nRobotsAt(m_row + 1, m_col) == 0 && m_row < m_arena->rows()) {//Down is safe to move
        move(DOWN);
        return "Moved.";
    }
    if (m_arena->nRobotsAt(m_row, m_col + 1) == 0 && m_col < m_arena->cols()) {//Right is safe to move
        move(RIGHT);
        return "Moved.";
    }
    if (m_arena->nRobotsAt(m_row, m_col - 1) == 0 && m_col > 1) {//Left is safe to move
        move(LEFT);
        return "Moved.";
    }
    stand(); //stand if nothing good can be done, expecting a robot to come closer
    return "Stood.";
}

void Player::stand()
{
    m_age++;
}

void Player::move(int dir)
{
    m_age++;
    switch (dir)
    {
        case UP:
        if (m_row > 1 && m_row <= m_arena->rows())
            m_row--;
        break;
        case DOWN:
        if (m_row > 0 && m_row < m_arena->rows())
            m_row++;
        break;
        case LEFT:
        if (m_col > 1 && m_col <= m_arena->cols())
            m_col--;
        break;
        case RIGHT:
        if (m_col > 0 && m_col < m_arena->cols())
            m_col++;
        break;
    }
}

bool Player::shoot(int dir)
{
    m_age++;

    if (rand() % 3 == 0)  // miss with 1/3 probability
        return false;

    switch (dir)
    {
        case UP:
        for (int i = 1; i <= MAXSHOTLEN; i++){
            if (m_arena->nRobotsAt(m_row-i, m_col) > 0 && m_row-i > 0){
                m_arena->damageRobotAt(m_row-i, m_col);
                return true;
            }
        }
        break;
        case DOWN:
        for (int i = 1; i <= MAXSHOTLEN; i++){
                if (m_arena->nRobotsAt(m_row+i, m_col) > 0 && m_row+i > 0){
                    m_arena->damageRobotAt(m_row+i, m_col);
                    return true;
                }
            }
            break;
        case LEFT:
        for (int i = 1; i <= MAXSHOTLEN; i++){
                if (m_arena->nRobotsAt(m_row, m_col-i) > 0 && m_row + i > 0){
                    m_arena->damageRobotAt(m_row, m_col-i);
                    return true;
                }
            }
        break;
        case RIGHT:
        for (int i = 1; i <= MAXSHOTLEN; i++){
                if (m_arena->nRobotsAt(m_row, m_col+i) > 0 && m_row-i > 0){
                    m_arena->damageRobotAt(m_row, m_col+i);
                    return true;
                }
            }
        break;
    }
    return false;
}

bool Player::isDead() const
{
    return m_dead; 
}

void Player::setDead()
{
    m_dead = true;
}
