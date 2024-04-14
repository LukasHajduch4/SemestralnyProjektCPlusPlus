//
// Created by Lukas Hajduch on 12/15/2023.
//
#include <iostream>
#include "gtest/gtest.h"

#include "User.h"
#include "Vehicle.h"
#include "Manager.h"

using namespace ::testing;

TEST(TestFirstTask, CreateUser) {
User u = User("Jozko Papsinda",500);
ASSERT_EQ("Jozko Papsinda", u.getUsername());
}
TEST(TestFirstTask, EmptyName) {
    User u = User("", 400);
    User u2 = User("Anna Klokovinova", 200);
    User u3 = User("", 350);
    ASSERT_EQ("RandomGeneratedUsername1", u.getUsername());
    ASSERT_EQ("Anna Klokovinova", u2.getUsername());
    ASSERT_EQ("RandomGeneratedUsername2", u3.getUsername());
}
TEST(TestFirstTask, SuccessfulAddingComments) {
    User u = User("Anna Klokocova", 125);
    ASSERT_EQ("Anna Klokocova", u.getUsername());
    ASSERT_TRUE(u.addReview("5.58:Hello all readers, this is a amazing driver"));
    ASSERT_EQ(std::stof("5.58"), u.averageRating());
}
TEST(TestFirstTask, FailedAddingCommentNoRating) {
    User u = User("Anna Klokocova", 158);
    ASSERT_EQ("Anna Klokocova", u.getUsername());
    ASSERT_FALSE(u.addReview(":Hello all readers, amazing driver"));
}

TEST(TestFirstTask, UnsuccessfulAddNoComment) {
    User u = User("Anna Klokocova", 190);
    ASSERT_EQ("Anna Klokocova", u.getUsername());
    ASSERT_FALSE(u.addReview("9.8:"));
}
TEST(TestFirstTask, BestRating) {
    User u = User("Katarína Domova", 154);
    ASSERT_TRUE(u.addReview("8.5:That was amazing ride"));
    ASSERT_TRUE(u.addReview("7.5:Not bad at all"));
    ASSERT_EQ("8.5:That was amazing ride", u.bestRating());
}
TEST(TestFirstTask, NoRating) {
    User u = User("Jozef Malý", 170);
    ASSERT_EQ("No ratings for this user", u.bestRating());
}

TEST(TestFirstTask, IDofScooter) {
    User u = User("Jozef Malý", 126);
    Scooter scooter1 = Scooter();
    ASSERT_EQ("KK001", scooter1.getIdentificationNumber());
}
TEST(TestFirstTask, AddingPriceToScooter) {
    Scooter scooter1 = Scooter();
    ASSERT_EQ("KK002", scooter1.getIdentificationNumber());
    ASSERT_TRUE(scooter1.addPricePerKilometer("   0.25 "));
    ASSERT_EQ("Identification Number: KK002\nType of vehicle: Scooter\nBattery: 100%\nPrice per Kilometer: 0.25", scooter1.showInfo());
}
TEST(TestFirstTask, FailedAddingPriceToScooter) {
    Scooter scooter1 = Scooter();
    ASSERT_EQ("KK003", scooter1.getIdentificationNumber());
    ASSERT_FALSE(scooter1.addPricePerKilometer("0.25k"));
}
TEST(TestFirstTask, ShowingInfoAboutElectricCar) {
    ElectricCar electricCar1 = ElectricCar("NZ949CU", "Model 3", 5, true, 3, 250, 500);
    ASSERT_EQ("AA001", electricCar1.getIdentificationNumber());
    ASSERT_TRUE(electricCar1.addPricePerKilometer("0.35"));
    ASSERT_EQ("Identification Number: AA001\nType of vehicle: Electric car\nBattery: 100%\nPrice per Kilometer: 0.35\nRegistration Number: NZ949CU\nAir Conditioning: YES\nNumber of Seats: 5\nModel of Car: Model 3\nAcceleration (0-100): 3 s\nMaximum Range: 500 km\nTop Speed: 250 km/h", electricCar1.showInfo());
}
TEST(TestFirstTask, FailedAddingElectricBikeInTrySuccesfulAfterCatch) {
    try {
        ElectricBike eBike1 = ElectricBike(4);
        ASSERT_EQ("BB001", eBike1.getIdentificationNumber());
        ASSERT_TRUE(eBike1.addPricePerKilometer("0.15"));
    }
    catch (const std::exception& e){
        ElectricBike eBike1 = ElectricBike(3);
        ASSERT_EQ("BB001", eBike1.getIdentificationNumber());
    }
}
TEST(TestFirstTask, AddingElectricBike) {
    ElectricBike eBike1 = ElectricBike(1);
    ASSERT_EQ("BB002", eBike1.getIdentificationNumber());
    ASSERT_TRUE(eBike1.addPricePerKilometer("0.15"));
    ASSERT_EQ("Type of bike: Cargo\nIdentification Number: BB002\nType of vehicle: Electric bike\nBattery: 100%\nPrice per Kilometer: 0.15", eBike1.showInfo());
}
TEST(TestFirstTask, ShowAllAvailableVehicles) {
    ElectricBike eBike1 = ElectricBike(1);
    ElectricBike eBike2 = ElectricBike(2);
    Scooter scooter1 = Scooter();
    ElectricCar electricCar1 = ElectricCar("NZ947CV", "ID4",5,true,4,210,520);
    Manager manager1 = Manager();
    manager1.addVehicle(&scooter1);
    manager1.addVehicle(&electricCar1);
    manager1.addVehicle(&eBike1);
    manager1.addVehicle(&eBike2);

    ASSERT_TRUE(eBike1.addPricePerKilometer("0.15"));
    ASSERT_TRUE(eBike2.addPricePerKilometer("0.22"));
    ASSERT_TRUE(scooter1.addPricePerKilometer("0.28"));
    ASSERT_TRUE(electricCar1.addPricePerKilometer("0.35"));
    ASSERT_EQ("Electric cars: AA002\nScooters: KK004\nElectric bikes: BB003\nBB004", manager1.showAvailableAllVehicles());
}
TEST(TestFirstTask, ShowAvailableVehiclesByType) {
    ElectricBike eBike1 = ElectricBike(1);
    ElectricBike eBike2 = ElectricBike(2);
    Scooter scooter1 = Scooter();
    ElectricCar electricCar1 = ElectricCar("NZ947CV", "ID4",5,true,4,210,520);
    Manager manager1 = Manager();
    manager1.addVehicle(&scooter1);
    manager1.addVehicle(&electricCar1);
    manager1.addVehicle(&eBike1);
    manager1.addVehicle(&eBike2);

    ASSERT_TRUE(eBike1.addPricePerKilometer("0.15"));
    ASSERT_TRUE(eBike2.addPricePerKilometer("0.22"));
    ASSERT_TRUE(scooter1.addPricePerKilometer("0.28"));
    ASSERT_TRUE(electricCar1.addPricePerKilometer("0.35"));
    ASSERT_EQ("AA003", manager1.showAvailableByType("Electric car"));
    ASSERT_EQ("BB005\nBB006", manager1.showAvailableByType("Electric bike"));
    ASSERT_EQ("KK005", manager1.showAvailableByType("Scooter"));
}
TEST(TestFirstTask, DeleteVehiclesByType) {
    ElectricBike eBike1 = ElectricBike(1);
    ElectricBike eBike2 = ElectricBike(2);
    Scooter scooter1 = Scooter();
    ElectricCar electricCar1 = ElectricCar("NZ947CV", "ID4",5,true,4,210,520);
    Manager manager1 = Manager();
    manager1.addVehicle(&scooter1);
    manager1.addVehicle(&electricCar1);
    manager1.addVehicle(&eBike1);
    manager1.addVehicle(&eBike2);

    ASSERT_TRUE(eBike1.addPricePerKilometer("0.15"));
    ASSERT_TRUE(eBike2.addPricePerKilometer("0.22"));
    ASSERT_TRUE(scooter1.addPricePerKilometer("0.28"));
    ASSERT_TRUE(electricCar1.addPricePerKilometer("0.35"));
    ASSERT_EQ("Electric cars: AA004\nScooters: KK006\nElectric bikes: BB007\nBB008", manager1.showAvailableAllVehicles());
    ASSERT_TRUE(manager1.deleteByType("Electric bike"));
    ASSERT_EQ("Electric cars: AA004\nScooters: KK006", manager1.showAvailableAllVehicles());
    ASSERT_EQ("No vehicles with this type", manager1.showAvailableByType("Electric bike"));
}
TEST(TestFirstTask, DeleteAllVehicles) {
    ElectricBike eBike1 = ElectricBike(1);
    ElectricBike eBike2 = ElectricBike(2);
    Scooter scooter1 = Scooter();
    ElectricCar electricCar1 = ElectricCar("NZ947CV", "ID4",5,true,4,210,520);
    Manager manager1 = Manager();
    manager1.addVehicle(&scooter1);
    manager1.addVehicle(&electricCar1);
    manager1.addVehicle(&eBike1);
    manager1.addVehicle(&eBike2);

    ASSERT_TRUE(eBike1.addPricePerKilometer("0.15"));
    ASSERT_TRUE(eBike2.addPricePerKilometer("0.22"));
    ASSERT_TRUE(scooter1.addPricePerKilometer("0.28"));
    ASSERT_TRUE(electricCar1.addPricePerKilometer("0.35"));
    ASSERT_EQ("Electric cars: AA005\nScooters: KK007\nElectric bikes: BB009\nBB010", manager1.showAvailableAllVehicles());
    manager1.deleteAllVehicles();
    ASSERT_EQ("No vehicles available", manager1.showAvailableAllVehicles());
}
TEST(TestFirstTask, DeleteByIdentificationNumber) {
    ElectricBike eBike1 = ElectricBike(1);
    ElectricBike eBike2 = ElectricBike(2);
    Scooter scooter1 = Scooter();
    ElectricCar electricCar1 = ElectricCar("NZ947CV", "ID4",5,true,4,210,520);
    Manager manager1 = Manager();
    manager1.addVehicle(&scooter1);
    manager1.addVehicle(&electricCar1);
    manager1.addVehicle(&eBike1);
    manager1.addVehicle(&eBike2);

    ASSERT_TRUE(eBike1.addPricePerKilometer("0.15"));
    ASSERT_TRUE(eBike2.addPricePerKilometer("0.22"));
    ASSERT_TRUE(scooter1.addPricePerKilometer("0.28"));
    ASSERT_TRUE(electricCar1.addPricePerKilometer("0.35"));
    ASSERT_EQ("Electric cars: AA006\nScooters: KK008\nElectric bikes: BB011\nBB012", manager1.showAvailableAllVehicles());
    ASSERT_TRUE(manager1.deleteByIdentificationNumber("BB011"));
    ASSERT_EQ("BB012", manager1.showAvailableByType("Electric bike"));
}
TEST(TestFirstTask, ReserveVehicle) {
    User u1 = User("", 400);
    ElectricBike eBike1 = ElectricBike(1);
    ElectricBike eBike2 = ElectricBike(2);
    Scooter scooter1 = Scooter();
    ElectricCar electricCar1 = ElectricCar("NZ947CV", "ID4",5,true,4,210,520);
    Manager manager1 = Manager();
    manager1.addVehicle(&scooter1);
    manager1.addVehicle(&electricCar1);
    manager1.addVehicle(&eBike1);
    manager1.addVehicle(&eBike2);
    manager1.addUser(&u1);
    ASSERT_TRUE(eBike1.addPricePerKilometer("0.15"));
    ASSERT_TRUE(eBike2.addPricePerKilometer("0.22"));
    ASSERT_TRUE(scooter1.addPricePerKilometer("0.28"));
    ASSERT_TRUE(electricCar1.addPricePerKilometer("0.35"));
    ASSERT_TRUE(manager1.reserveVehicle(u1,eBike1,40));
    ASSERT_EQ(394,u1.getMoney());
    ASSERT_EQ(60, eBike1.getBattery());
    ASSERT_TRUE(manager1.reserveVehicle(u1,eBike1,55));
    ASSERT_EQ(385.75,u1.getMoney());
    ASSERT_FALSE(eBike1.getAvailability());
    ASSERT_EQ("BB014",manager1.showAvailableByType("Electric bike"));
}
TEST(TestFirstTask, AddRide) {
    User u1 = User("Igor Hladny", 547);
    u1.addRide("Bratislava:Kosice:10:350:Skoda:White:3");
    ASSERT_EQ(
            "Ride ID: ID1\nStart location: Bratislava\nDestination: Kosice\nPrice per 100 km: 10\nRoute length: 350\nBrand of car: Skoda\nColor: White",
            u1.findRideWithId("ID1").showInfoAboutRide());
    ASSERT_TRUE(u1.removeRide("ID1"));
    Ride returnedRide = u1.findRideWithId("ID1");
    ASSERT_EQ("Ride ID: -\nStart location: -\nDestination: -\nPrice per 100 km: 0\nRoute length: 0\nBrand of car: -\nColor: -", returnedRide.showInfoAboutRide());
}
TEST(TestFirstTask, FindRides){
    Manager manager1 = Manager();
    User user1 = User("Stefan Horor", 248);
    user1.addRide("Bratislava:Kosice:10:350:Skoda:White:3");
    manager1.addUser(&user1);
    std::vector <Ride*> oneRide = manager1.findRides("Bratislava", "Kosice");
    ASSERT_EQ("1. ride: Ride ID: ID2\nStart location: Bratislava\nDestination: Kosice\nPrice per 100 km: 10\nRoute length: 350\nBrand of car: Skoda\nColor: White",manager1.showInfoAboutRides(oneRide));
    ASSERT_TRUE(user1.removeRide("ID2"));

    ASSERT_EQ("No rides from this start location to that destination",manager1.showInfoAboutRides(manager1.findRides("Bratislava", "Kosice")));
}
TEST(TestFirstTask, ReserveRide){
    Manager manager1 = Manager();
    User user1 = User("Ivan Klokocina", 580);
    User user2 = User("", 259);
    user1.addRide("Nitra:Banska Bystrica:18:150:Volkswagen:Black:2");
    manager1.addUser(&user1);
    Ride *ride1 = manager1.findRides("Nitra", "Banska Bystrica")[0];
    ASSERT_TRUE(manager1.reserveRide(user2, *ride1));
    manager1.completePayment(user2, *ride1);
    ASSERT_EQ(232, user2.getMoney());
}
TEST(TestFirstTask, SaveAndReadRideFromFile){
    Manager manager1 = Manager();
    User user1 = User("Ivan Klokocina", 580);
    User user2 = User("Jozef Abraham", 289);

    user1.addRide("Nove Zamky:Brno:25:247:Tesla:Red:4");
    manager1.addUser(&user1);
    Ride *ride1 = manager1.findRides("Nove Zamky", "Brno")[0];
    manager1.saveRideInfoIntoFile(user2, *ride1);
    ASSERT_EQ("ID4:Nove Zamky:Brno:25:247:Tesla:Red", manager1.readRideInfoFromFile(user2.getUsername()+ride1->getRideIdentificationNumber()+".txt"));
}