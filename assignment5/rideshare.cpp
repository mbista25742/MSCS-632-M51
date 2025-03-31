#include <iostream>
#include <string>
#include <vector>

class Ride {
public:
    Ride(int id, const std::string& pickup, const std::string& dropoff, double dist)
        : rideID(id), pickupLocation(pickup), dropoffLocation(dropoff), distance(dist) {
        calculateFare(); 
    }

    virtual ~Ride() {} // Virtual destructor for polymorphism

    int getRideID() const { return rideID; }
    std::string getPickupLocation() const { return pickupLocation; }
    std::string getDropoffLocation() const { return dropoffLocation; }
    double getDistance() const { return distance; }
    double getFare() const { return fare; }

    virtual void calculateFare() {
        fare = distance * 10.0; // Default fare calculation
    }

    virtual std::string rideDetails() const {
        return "Ride ID: " + std::to_string(rideID) +
               ", Pickup: " + pickupLocation +
               ", Dropoff: " + dropoffLocation +
               ", Distance: " + std::to_string(distance) +
               ", Fare: " + std::to_string(fare);
    }

protected:
    double distance; // Changed to protected
    double fare;
private:
    int rideID;
    std::string pickupLocation;
    std::string dropoffLocation;
};

class StandardRide : public Ride {
public:
    StandardRide(int id, const std::string& pickup, const std::string& dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    void calculateFare() override {
        fare = distance * 10.0; // Standard fare calculation
    }
};

class PremiumRide : public Ride {
public:
    PremiumRide(int id, const std::string& pickup, const std::string& dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    void calculateFare() override {
        fare = distance * 15.0; // Premium fare calculation
    }
};

class Driver {
public:
    Driver(int id, const std::string& name, double rating)
        : driverID(id), name(name), rating(rating) {}

    void addRide(Ride* ride) {
        assignedRides.push_back(ride);
    }

    void completeRide(Ride* ride) {
        for (auto it = assignedRides.begin(); it != assignedRides.end(); ++it) {
            if (*it == ride) {
                assignedRides.erase(it);
                completedRides.push_back(ride);
                return;
            }
        }
    }

    std::string getDriverInfo() const {
        return "Driver ID: " + std::to_string(driverID) +
               ", Name: " + name +
               ", Rating: " + std::to_string(rating) +
               ", Assigned Rides: " + std::to_string(assignedRides.size()) +
               ", Completed Rides: " + std::to_string(completedRides.size());
    }

private:
    int driverID;
    std::string name;
    double rating;
    std::vector<Ride*> assignedRides;
    std::vector<Ride*> completedRides;
};

class Rider {
public:
    Rider(int id, const std::string& name) : riderID(id), name(name) {}

    void requestRide(Ride* ride) {
        requestedRides.push_back(ride);
    }

    void viewRides() const {
        for (const auto& ride : requestedRides) {
            std::cout << ride->rideDetails() << std::endl;
        }
    }

private:
    int riderID;
    std::string name;
    std::vector<Ride*> requestedRides;
};

int main() {
    std::vector<Ride*> rides;
    rides.push_back(new StandardRide(1, "Downtown", "Airport", 10));
    rides.push_back(new PremiumRide(2, "Fort Worth", "Plano", 35));
    rides.push_back(new Ride(3, "Home", "Office", 5));

    for (const auto& ride : rides) {
        std::cout << ride->rideDetails() << std::endl;
        std::cout << "Fare: " << ride->getFare() << std::endl;
    }

    // Clean up memory (important!)
    for (auto ride : rides) {
        delete ride;
    }

    return 0;
}