#pragma once
#include<string>
#include<vector>
#include"ItemToPurchase.h"
#include<iostream>

#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
using namespace std;


class ShoppingCart {
public:
	ShoppingCart();
	ShoppingCart(string customerName, string creationDate);
	int FindIndexInCart(string name);	
	string GetItemName(int index);
	int GetItemQuantity(int index);
	double GetItemPrice(int index);
	double GetItemTotalPrice(int index);
	string GetItemDescription(int index);	
	string GetCustomerName();
	string GetCreationDate();
	void SetCustomerName(string customerName);
	void SetCreationDate(string creationDate);
	void AddItemToCart(string itemName, string itemDescription, double itemPrice, int itemQuantity);
	/*void AddItemToCart(string itemName, string itemDescription);
	void AddItemToCart(double itemPrice, int itemQuantity);
	void AddItemToCart(double itemPrice); //potential future overloads if nesecary
	void AddItemToCart(int itemQuantity);
	void AddItemToCart(string itemName);
	*/
	void RemoveItemFromCart(string itemToRemoveName);
	void UpdateItemQuantity(string itemToUpdateName, int newQuantity);
	int GetNumberItems();
	double GetTotalCost();
	void OutputCart();
	void OutputDescriptions();



private:
	string customerName;
	string creationDate;
	vector<ItemToPurchase> itemsInCart;




};






#endif
