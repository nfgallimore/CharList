#ifndef CHARLIST_HPP
#define CHARLIST_HPP

/**** if the order is required, use insert() only ***///
class CharList
{
	private:
		struct Node
		{
			char value;
			Node* next;
		};

	public:

		// constructor
		CharList();	

		// print the list
		void displayList() const;	

		// sorts the list
		void sort();

		// clears the list
		void clear();

		// append a value ot the end of the list
		bool appendNode(char);

		// insert value between. This method will be called if you want to maintain theo rder of all values
		bool insertNode(char);

		// delete value from the list. return true of successful, false if failed
		bool deleteNode(char);

		// search a value in the list, return true if found
		bool search(char);
	
		// destructor
		virtual ~CharList();
		
	private:
		Node* head;
};

#endif // CHARLIST_HPP