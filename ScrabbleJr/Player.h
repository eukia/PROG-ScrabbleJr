//
// Created by ritam on 04/05/20.
//

#ifndef PROGT2_PLAYER_H
#define PROGT2_PLAYER_H

#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include "../CommonFiles/Board.h"
#include "gameIO.h"


class Player {

public:

    Player();

    explicit Player(const std::string &name_);

    void showHand();

    std::string getName() const;

    unsigned getScore() const;

    void play(char letter, std::pair<char, char> coords, Board &board);

    bool isValidMove(char letter, std::pair<char, char> coords, Board board);

    std::vector<std::pair<char, char> > getPlayable(const Board &board);

    void removeTile(char tile);

    bool hasTile(char tile);

    void addTiles(const std::vector<char> &tiles);

    std::vector<char> getHand();

    std::string error{};

    void incrementScore();

    std::vector<std::string> getHints(const Board &board);

    bool operator >(const Player &otherPlayer) const;

private:

    std::vector<std::string> errors = {
            "ERROR: You do not have that tile in your hand.\n", "ERROR: Can't place that tile there.\n"
    };

    std::string _name;

    std::vector<char> _hand;

    unsigned _score{};

};


#endif //PROGT2_PLAYER_H
