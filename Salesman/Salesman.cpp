#include <SFML/Graphics.hpp>
#include<iostream>
#include"Graph.h"
using namespace std;
struct CurrBranch {
    int currentVertex;
    std::vector<int> path;
    int distance;
    CurrBranch(int vertex, const std::vector<int>& p, int dist) : currentVertex(vertex), path(p), distance(dist) {}
};
std::pair<int, std::vector<int>> solveTravelingSalesmanProblem(std::vector<std::vector<int>>& matrix, int vrtcnt) {
    
    int n = vrtcnt;
    std::vector<int> vertexIndices(n);
    int minDistance = 10000000;
    std::vector<int> minPath;
    std::vector<CurrBranch> edgestatus;
    edgestatus.emplace_back(vertexIndices[0], std::vector<int>{vertexIndices[0]}, 0);
    for (int i = 0; i < n; ++i) {
        vertexIndices[i] = i;
    }

    
    while (!edgestatus.empty()) {
        auto currentState = edgestatus.back();
        edgestatus.pop_back();
        if (currentState.path.size() == n) {
            int finalDistance = currentState.distance + matrix[currentState.currentVertex][vertexIndices[0]];
            
            if (finalDistance < minDistance) {
                minDistance = finalDistance;
                minPath = currentState.path;
                minPath.push_back(vertexIndices[0]);
            }
        }
        
        
        else {
            for (int i = 1; i < n; ++i) {
                int nextVertex = vertexIndices[i];
                if (std::find(currentState.path.begin(), currentState.path.end(), nextVertex) == currentState.path.end()) {
                    int distanceToNext = matrix[currentState.currentVertex][nextVertex];
                    if (distanceToNext != 0 && currentState.distance + distanceToNext < minDistance) {
                        std::vector<int> newPath = currentState.path;
                        newPath.push_back(nextVertex);

                        edgestatus.emplace_back(nextVertex, newPath, currentState.distance + distanceToNext);
                    }
                }
            }
        }
    }

    return std::make_pair(minDistance, minPath);
}

int convertToASCII(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        return (int)s[i];
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    Graph newGraph(5);
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Graph");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);
    sf::Font font;
    font.loadFromFile("aerial.ttf");

    vector<sf::Text> Liters(20);
    vector<sf::CircleShape> points(newGraph.VertexCount);
    map<pair<int, int>, pair<sf::Vertex, sf::Vertex>> edgs;
    vector<pair<sf::Vertex, sf::Vertex>> edgespos;
    vector <pair<pair<sf::Vertex, sf::Vertex>, sf::Text>> edge_value(20);

    sf::Font buttonfont;
    buttonfont.loadFromFile("gnyrwn971.ttf");
    sf::Text add_vertex_buttontext;
    add_vertex_buttontext.setString("add vertex");
    add_vertex_buttontext.setFont(buttonfont);
    add_vertex_buttontext.setPosition(25, 110);

    sf::RectangleShape button1(sf::Vector2f(180, 65));
    button1.setFillColor(sf::Color::Red);
    button1.setPosition(0, 100);

    sf::Text add_edge_buttontext;
    add_edge_buttontext.setString("add edge");
    add_edge_buttontext.setFont(buttonfont);
    add_edge_buttontext.setPosition(25, 220);

    sf::RectangleShape button2(sf::Vector2f(180, 65));
    button2.setFillColor(sf::Color::Red);
    button2.setPosition(0, 200);

    sf::Text pop_vertex_button;
    pop_vertex_button.setString("delete vertex");
    pop_vertex_button.setFont(buttonfont);
    pop_vertex_button.setPosition(25, 310);

    sf::RectangleShape button3(sf::Vector2f(180, 65));
    button3.setFillColor(sf::Color::Red);
    button3.setPosition(0, 300);

    sf::RectangleShape button4(sf::Vector2f(180, 65));
    button4.setFillColor(sf::Color::Red);
    button4.setPosition(0, 400);

    sf::Text pop_edge_button;
    pop_edge_button.setString("delete edge");
    pop_edge_button.setFont(buttonfont);
    pop_edge_button.setPosition(25, 410);

    sf::RectangleShape button5(sf::Vector2f(180, 65));
    button5.setFillColor(sf::Color::Red);
    button5.setPosition(0, 500);

    sf::Text salesman;
    salesman.setString("salesman");
    salesman.setFont(buttonfont);
    salesman.setPosition(25, 510);

    sf::Text salesman_result;
    salesman_result.setFont(buttonfont);
    salesman_result.setPosition(512, 700);

    sf::Text sailsman_pts;
    salesman_result.setFont(buttonfont);
    salesman_result.setPosition(512, 680);

    for (int i = 0;i < newGraph.VertexCount;i++) {
        points[i].setRadius(25.f);
        points[i].setPosition(200 + rand() % 400, 100 + rand() % 400);
        points[i].setFillColor(sf::Color::Green);
        Liters[i].setString((char)newGraph.symbol_num);
        Liters[i].setFillColor(sf::Color::Black);
        Liters[i].setFont(font);
        Liters[i].setCharacterSize(20);
        Liters[i].setPosition(points[i].getPosition().x + 15, points[i].getPosition().y + 15);
        (newGraph.symbol_num)++;
    }
    while (window.isOpen())
    {
        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
        sf::Vector2f pos = window.mapPixelToCoords(pixelPos);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
                if (event.key.code == sf::Mouse::Left) {
                    for (int i = 0;i < newGraph.VertexCount;i++) {
                        if (points[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                            sf::Vector2f mousePos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                            sf::Vector2f offset = mousePos - points[i].getPosition();
                            while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                                points[i].setFillColor(sf::Color::Red);
                                mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
                                points[i].setPosition(mousePos - offset);
                                Liters[i].setPosition(mousePos - offset);
                                Liters[i].setPosition(Liters[i].getPosition().x + 10, Liters[i].getPosition().y + 10);
                            }
                        }
                    }
                    if (button1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        sf::CircleShape tmp_circle;
                        tmp_circle.setRadius(25.f);
                        tmp_circle.setPosition(200 + rand() % 400, 100 + rand() % 400);
                        tmp_circle.setFillColor(sf::Color::Green);
                        points.push_back(tmp_circle);
                        sf::Text tmp_text;
                        tmp_text.setString((char)(newGraph.symbol_num));
                        tmp_text.setFillColor(sf::Color::Black);
                        tmp_text.setFont(font);
                        tmp_text.setCharacterSize(20);
                        tmp_text.setPosition(tmp_circle.getPosition().x + 15, tmp_circle.getPosition().y + 15);
                        Liters[newGraph.VertexCount] = tmp_text;
                        newGraph.symbol_num++;
                        newGraph.VertexCount++;
                    }
                    if (button2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        int from, to, value;
                        int ans;
                        string from1, to1;
                        char tmp;
                        cout << "1.Двунаправленное ребро" << endl;
                        cout << "2.Однонаправленное ребро" << endl;
                        cin >> ans;
                        if (ans == 2) {
                            cout << "from:";
                            cin >> from1;
                            from = convertToASCII(from1);
                            from -= 65;
                            cout << "to:";
                            cin >> to1;
                            to = convertToASCII(to1);
                            to -= 65;
                            cout << "value:";
                            cin >> value;
                            newGraph.add_edge(from, to, value);
                            cout << endl;
                            for (int m = 0;m < newGraph.VertexCount;m++) {
                                for (int n = 0;n < newGraph.VertexCount;n++) {
                                    cout << newGraph.matrix[m][n] << " ";
                                }
                                cout << endl;
                            }
                            cout << endl;
                        }
                        if (ans == 1) {
                            cout << "from:";
                            cin >> from1;
                            from = convertToASCII(from1);
                            from -= 65;
                            cout << "to:";
                            cin >> to1;
                            to = convertToASCII(to1);
                            to -= 65;
                            cout << "value:";
                            cin >> value;
                            newGraph.add_edge(from, to, value);
                            newGraph.add_edge(to, from, value);
                            cout << endl;
                            for (int m = 0;m < newGraph.VertexCount;m++) {
                                for (int n = 0;n < newGraph.VertexCount;n++) {
                                    cout << newGraph.matrix[m][n] << " ";
                                }
                                cout << endl;
                            }
                            cout << endl;
                        }

                    }
                    if (button3.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        Liters[newGraph.VertexCount - 1] = Liters[newGraph.VertexCount + 2];
                        points.pop_back();
                        newGraph.VertexCount--;
                        newGraph.symbol_num--;
                        vector<pair<int, int>> tmpvec;
                        for (auto i : newGraph.edges) {
                            if (i.second != newGraph.VertexCount && i.first != newGraph.VertexCount) {
                                tmpvec.push_back(i);
                            }
                            else {
                                newGraph.EdgeCount--;
                                edgs.erase(i);
                            }
                        }
                        newGraph.edges = tmpvec;
                    }
                    if (button4.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        int from, to;
                        cout << "from:";
                        cin >> from;
                        cout << "to:";
                        cin >> to;
                        vector<pair<int, int>> tmpvec;
                        for (auto i : newGraph.edges) {
                            if (i.first != from || i.second != to) {
                                tmpvec.push_back(i);
                            }
                        }
                        newGraph.edges = tmpvec;
                        newGraph.EdgeCount--;
                    }
                    if (button5.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        vector<int> path(newGraph.VertexCount + 1);
                        int num = newGraph.VertexCount;
                        for (int i = 0;i < newGraph.VertexCount;i++) {
                            for (int j = 0;j < newGraph.VertexCount;j++) {
                                if (i == j) {
                                    newGraph.matrix[i][j] = -1;
                                }
                                if (newGraph.matrix[i][j] == 0) {
                                    newGraph.matrix[i][j] = 100000;
                                }
                            }
                        }
                        vector<vector<int>> tmp = newGraph.matrix;
                        pair<int, vector<int>> res = solveTravelingSalesmanProblem(tmp, newGraph.VertexCount);
                        for (int i = 0;i < newGraph.VertexCount;i++) {
                            cout << char(res.second[i] + 65) << "->";
                        }
                        cout << char(res.second[0] + 65) << endl;
                        cout << res.first << endl;

                    }
                }
            if (event.type == sf::Event::MouseButtonReleased)
                if (event.key.code == sf::Mouse::Left)
                    for (int i = 0;i < newGraph.VertexCount;i++) {
                        points[i].setFillColor(sf::Color::Green);
                    }

        }
        window.clear(sf::Color::Blue);
        int litcnt = 0;
        for (int i = 0;i < newGraph.EdgeCount;i++) {
            pair<int, int> curr_edge = newGraph.edges[i];
            sf::Text tmptxt;
            tmptxt.setFont(font);
            tmptxt.setString(to_string(newGraph.matrix[curr_edge.first][curr_edge.second]));
            pair<sf::Vertex, sf::Vertex> newEdge = make_pair(sf::Vertex(sf::Vector2f(Liters[curr_edge.first].getPosition().x + 15, Liters[curr_edge.first].getPosition().y + 15)), sf::Vertex(sf::Vector2f(Liters[curr_edge.second].getPosition().x + 15, Liters[curr_edge.second].getPosition().y + 15)));
            pair<pair<sf::Vertex, sf::Vertex>, sf::Text> np = make_pair(newEdge, tmptxt);
            edge_value[litcnt] = np;
            edgespos.push_back(newEdge);
            litcnt++;
        }

        for (auto t : edgespos) {
            sf::Vertex line[] = {
                sf::Vertex(t.first),
                sf::Vertex(t.second)
            };
            window.draw(line, 2, sf::Lines);
            for (auto j : edge_value) {
                if (j.first.first.position == t.first.position && j.first.second.position == t.second.position) {
                    j.second.setPosition((t.second.position.x + t.first.position.x) / 2, (t.second.position.y + t.first.position.y) / 2);
                    j.second.setFillColor(sf::Color::Black);
                    window.draw(j.second);
                }
            }


        }
        for (int i = 0;i < newGraph.VertexCount;i++) {
            window.draw(points[i]);
        }
        for (auto i : edgespos) {
            sf::Vertex line[] = {
                sf::Vertex(i.first),
                sf::Vertex(i.second)
            };
            float angle = atan2(line[1].position.y - line[0].position.y, line[1].position.x - line[0].position.x);
            float arrowSize = std::min(std::hypot(line[1].position.y - line[0].position.y, line[1].position.x - line[0].position.x), 50.f) * 0.3f + 15;
            sf::Vector2f arrowheadPos = sf::Vector2f(line[1].position.x - std::cos(angle + 3.14159265359f / 6) * arrowSize, line[1].position.y - std::sin(angle + 3.14159265359f / 6) * arrowSize);
            sf::VertexArray arrowhead(sf::Triangles, 3);
            arrowhead[0].position = line[1].position;
            arrowhead[1].position = arrowheadPos;
            arrowhead[2].position = sf::Vector2f(line[1].position.x - std::cos(angle - 3.14159265359f / 6) * arrowSize, line[1].position.y - std::sin(angle - 3.14159265359f / 6) * arrowSize);
            arrowhead[0].color = sf::Color::White;
            arrowhead[1].color = sf::Color::White;
            arrowhead[2].color = sf::Color::White;
            window.draw(arrowhead);
        }
        edgespos.clear();
        int cnt = 0;
        for (auto i : Liters) {
            window.draw(i);
            cnt++;
            if (cnt == newGraph.VertexCount) {
                break;
            }
        }
        window.draw(button1);
        window.draw(add_vertex_buttontext);
        window.draw(button2);
        window.draw(add_edge_buttontext);
        window.draw(button3);
        window.draw(pop_vertex_button);
        window.draw(button4);
        window.draw(pop_edge_button);
        window.draw(button5);
        window.draw(salesman);
        window.display();

    }
}
