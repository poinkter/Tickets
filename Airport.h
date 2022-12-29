#include <string>

using namespace std;

class Airport{
    string airportName;
public:
    Airport();
    Airport(string);
    Airport(Airport&);
    Airport& setAirportName(string);
    inline string getAirportName() const;

    virtual void view();

    virtual ~Airport(){};
};

class Terminal: public Airport{
    string terminalName;
    static double parkingPrice;
public:
    Terminal();
    Terminal(string, string);
    Terminal(Terminal&);
    inline string getTerminalName() const;
    inline static double getParkingPrice();
    Terminal& setTerminalName(string);

    void view();

    ~Terminal(){};
};

class Airplane {
    string company;
    string model;
public:
    Airplane();
    Airplane(string, string);
    Airplane(Airplane&);
    inline string getCompany() const;
    inline string getModel() const;
    Airplane& setCompany(string);
    Airplane& setModel(string);

    ~Airplane(){};
};
