#pragma once

#include <vector>
class Player {
private:
	std::string name;
	int points;
public:
    Player() {
        name = "";
        points =0;
    }
    Player(std::string new_name, int new_points) {
        name = new_name;
        points = new_points;
    }
    void setName(std::string new_name)
    {
        name = new_name;

    }
    std::string getName()
    {
        return name;
    }
    void setPoints(int new_points)
    {
        name = new_points;

    }
    int getPoints()
    {
        return points;
    }
      
};

bool operator > (Player player1, Player player2)
{
    return player1.getPoints() > player2.getPoints();
}
bool operator < (Player player1, Player player2)
{
    return player1.getPoints() < player2.getPoints();
}
bool operator == (Player player1, Player player2)
{
    return player1.getPoints() == player2.getPoints();
}
bool operator != (Player player1, Player player2)
{
    return player1.getPoints() != player2.getPoints();
}
std::vector<Player> playerOutDocument() {

    std::vector<Player> players;
    std::string name;
    int point;
    std::ifstream in("score.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (in >> name >> point)
        {
            players.push_back(Player(name, point));
        }
    }
    in.close();
    return players;

}

void playerInDocument(std::vector<Player> new_player) {
    std::ofstream out("score.txt");

    if (out.is_open())
    {
        for (int i = 0; i < new_player.size(); i++)
        {
            out << new_player[i].getName() << " " << new_player[i].getPoints() << std::endl;
        }
    }
    out.close();
}
void printPlayer(std::vector<Player> players) {
    for (int i = 0; i < players.size(); i++)
    {
        std::cout << players[i].getName() << " - " << players[i].getPoints() << std::endl;
    }
}

//Player swapPlayer(Player player1, Player player2) {
//    Player player3;
//    player3.setName(player1.getName());
//    player3.setPoints(player1.getPoints());
//    player1.setName(player2.getName());
//    player1.setPoints(player2.getPoints());
//    player2.setName(player3.getName());
//    player2.setPoints(player3.getPoints());
//
//}
void sortNewPlayers(Player player) {
    std::vector<Player> players = playerOutDocument();
    for (int i = 0; i < players.size(); i++) {
        if (players[i].getName() == player.getName()) {
            if (players[i].getPoints() < player.getPoints()) {
                players[i].setPoints(player.getPoints());
            }
        }
        else {
            players.push_back(player);
        }


        //sort


        playerInDocument(players);
    }
}