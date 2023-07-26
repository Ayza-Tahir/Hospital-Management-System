
#include<iostream>
#include<string>
#include<queue>
#include<climits> // check values, for BST

using namespace std;

class PatientRecord
{

public:

	int patient_id;
	string patient_name;
	string admission_date;
	string disease_diagnosis;
	int status;                              //admitted/discharged

	PatientRecord()
	{
		patient_id = NULL;
		patient_name = '\0';
		admission_date = '\0';
		disease_diagnosis = '\0';
		status = NULL;

	}
	
	PatientRecord(int patient_id, string patient_name, string admission_date, string disease_diagnosis, int status)
	{

		
	   this->patient_id = patient_id;
		this->patient_name = patient_name;
		this->admission_date = admission_date;
		this->disease_diagnosis = disease_diagnosis;
		this->status = status;
		
	}

};


class TNode
{
public:

	TNode* leftChild;
	TNode* rightChild;
	PatientRecord record;

	TNode(PatientRecord pr)
	{
		leftChild = NULL;
		rightChild = NULL;
		record = pr;
	}

};


class HospitalData
{
public:

	TNode* root;
	int size;

	HospitalData()
	{
		root = NULL;
		size = NULL;
	}
	

	//rotations
	TNode* rotateRight(TNode* root)
	{
		TNode* NewNode = root->leftChild;
		root->leftChild = NewNode->rightChild;           //point NULL
		NewNode->rightChild = root;
		return NewNode;
	}

	TNode* rotateLeft(TNode* root)
	{
		TNode* NewNode = root->rightChild;
		
		root->rightChild = NewNode->leftChild;      //point NULL
		NewNode->leftChild = root;
		return NewNode;
	}

	//insertion
	TNode* insert(TNode*root,PatientRecord record) 
	{
		
		if (root == NULL)
		{
			TNode* newNode = new TNode(record);
			return newNode;
		}

		if (record.patient_id < root->record.patient_id)  
		{
			root->leftChild = insert(root->leftChild,record);
			if (record.status == 1)          //place root node when it is newly admitted
			{
				root= rotateRight(root); //root node
			}
		}
		else if (record.patient_id > root->record.patient_id)
		{
			root->rightChild = insert(root->rightChild,record);
			if (record.status == 1)                  //place root node when it is newly admitted
			{
				root=rotateLeft(root);
			}
		}

		return root;
	}

	void insertAtRoot(PatientRecord record)
	{
		root = insert(root, record);
	}

	////Tranversal
	
	//Output Patient 

	void inorderR(TNode* root)
	{

		if (root == NULL)
		{
			return;
		}
		if (root != nullptr)
		{
			inorderR(root->leftChild);
			cout << "Patient ID " << " " << ":";
			cout << root->record.patient_id;
			cout << endl;
			cout << "Patient name " << " " << ":";
			cout << root->record.patient_name;
			cout << endl;
			cout << "Patient admission date" << " " << ":";
			cout << root->record.admission_date;
			cout << endl;
			cout << "Patient disease diagnosis " << " " << ":";
			cout << root->record.disease_diagnosis;
			cout << endl;
			if (root->record.status == 1)
			{
				cout << "Patient Status :" << "Admitted" << endl;
			}
			else if (root->record.status == 0)
			{
				cout << "Patient Status :" << "Discharged" << endl;
			}
			cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-_-_-_-_-_-" << endl;
			cout << endl;
			inorderR(root->rightChild);
			cout << endl;
		}

	}
	void inorder()
	{	
			inorderR(root);
	}

	void preorderR(TNode* root)
	{
		if (root == NULL)
		{
			return;
		}
		if (root != NULL)
		{
			cout << "Patient ID " << " " << ":";
			cout << root->record.patient_id;
			cout << endl;
			cout << "Patient name " << " " << ":";
			cout << root->record.patient_name;
			cout << endl;
			cout << "Patient admission date" << " " << ":";
			cout << root->record.admission_date;
			cout << endl;
			cout << "Patient disease diagnosis " << " " << ":";
			cout << root->record.disease_diagnosis;
			cout << endl;
			if (root->record.status == 1)
			{
				cout << "Patient Status :" << "Admitted" << endl;
			}
			else if (root->record.status == 0)
			{
				cout << "Patient Status :" << "Discharged" << endl;
			}

			cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-__-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
			cout << endl;

			preorderR(root->leftChild);
			preorderR(root->rightChild);

		}

	}
	void preorder()
	{
		preorderR(root);
	}

	void postorderR(TNode* root)
	{
		if (root == NULL)
		{
			return;
		}
		if (root != NULL)
		{
			postorderR(root->leftChild);
			postorderR(root->rightChild);

			cout << "Patient ID " << " " << ":";
			cout << root->record.patient_id;
			cout << endl;
			cout << "Patient name " << " " << ":";
			cout << root->record.patient_name;
			cout << endl;
			cout << "Patient admission date" << " " << ":";
			cout << root->record.admission_date;
			cout << endl;
			cout << "Patient disease diagnosis " << " " << ":";
			cout << root->record.disease_diagnosis;
			cout << endl;
			if (root->record.status == 1)
			{
				cout << "Patient Status :" << "Admitted" << endl;
			}
			else if (root->record.status == 0)
			{
				cout << "Patient Status :" << "Discharged" << endl;
			}


			cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
			cout << endl;
		}
	}
	void postorder()
	{
		postorderR(root);
	}

	void level_OrderR(TNode* root)
	{
		if (root == NULL)
		{
			cout << "There is no Patient Record in Hospital Data" << endl;
			return;
		}

		queue<TNode*>q;
		q.push(root);

		while (!q.empty())
		{
			TNode* node = q.front();
			q.pop();
			cout << "Patient ID " << " " << ":";
			cout << node->record.patient_id;
			cout << endl;
			cout << "Patient name " << " " << ":";
			cout << node->record.patient_name;
			cout << endl;
			cout << "Patient admission date" << " " << ":";
			cout << node->record.admission_date;
			cout << endl;
			cout << "Patient disease diagnosis " << " " << ":";
			cout << node->record.disease_diagnosis;
			cout << endl;
			if (node->record.status == 1)
			{
				cout << "Patient Status :" << "Admitted" << endl;
			}
			else if (node->record.status == 0)
			{
				cout << "Patient Status :" << "Discharged" << endl;
			}

			cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
			cout << endl;

			if (node->leftChild != NULL)
			{
				q.push(node->leftChild);
			}
			if (node->rightChild != NULL)
			{
				q.push(node->rightChild);
			}

		}
	}
	void level_Order()
	{
		level_OrderR(root);
	}

	////Output of Admitted patients

	void inorderAR(TNode* root)
	{
		if (root == NULL)
		{
			
			return;
		}
		if (root != NULL)
		{
			inorderAR(root->leftChild);
			if (root->record.status == 1)
			{
				cout << "Patient ID " << " " << ":";
				cout << root->record.patient_id;
				cout << endl;
				cout << "Patient name " << " " << ":";
				cout << root->record.patient_name;
				cout << endl;
				cout << "Patient admission date" << " " << ":";
				cout << root->record.admission_date;
				cout << endl;
				cout << "Patient disease diagnosis " << " " << ":";
				cout << root->record.disease_diagnosis;
				cout << endl;
				if (root->record.status == 1)
				{
					cout << "Patient Status :" << "Admitted" << endl;
				}
				else if (root->record.status == 0)
				{
					cout << "Patient Status :" << "Discharged" << endl;
				}
				cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-__-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
				cout << endl;
			}
			inorderAR(root->rightChild);
			cout << endl;
		}

	}
	void inorderA()
	{
		inorderAR(root);
	}

	void preorderAR(TNode* root)
	{
		if (root == NULL)
		{
			
			return;
		}
		if (root != NULL)
		{
			if (root->record.status)
			{
				cout << "Patient ID " << " " << ":";
				cout << root->record.patient_id;
				cout << endl;
				cout << "Patient name " << " " << ":";
				cout << root->record.patient_name;
				cout << endl;
				cout << "Patient admission date" << " " << ":";
				cout << root->record.admission_date;
				cout << endl;
				cout << "Patient disease diagnosis " << " " << ":";
				cout << root->record.disease_diagnosis;
				cout << endl;
				if (root->record.status == 1)
				{
					cout << "Patient Status :" << "Admitted" << endl;
				}
				else if (root->record.status == 0)
				{
					cout << "Patient Status :" << "Discharged" << endl;
				}

				cout << "_-_-_-_-_-_-__-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
				cout << endl;
			}

			preorderAR(root->leftChild);
			preorderAR(root->rightChild);

		}

	}
	void preorderA()
	{
		preorderAR(root);
	}

	void postorderAR(TNode* root)
	{
		if (root == NULL)
		{
			
			return;
		}
		if (root != NULL)
		{
			if (root->record.status == 1)
			{
				postorderAR(root->leftChild);
				postorderAR(root->rightChild);

				cout << "Patient ID " << " " << ":";
				cout << root->record.patient_id;
				cout << endl;
				cout << "Patient name " << " " << ":";
				cout << root->record.patient_name;
				cout << endl;
				cout << "Patient admission date" << " " << ":";
				cout << root->record.admission_date;
				cout << endl;
				cout << "Patient disease diagnosis " << " " << ":";
				cout << root->record.disease_diagnosis;
				cout << endl;
				if (root->record.status == 1)
				{
					cout << "Patient Status :" << "Admitted" << endl;
				}
				else if (root->record.status == 0)
				{
					cout << "Patient Status :" << "Discharged" << endl;
				}


				cout << "_-_-_-__-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
				cout << endl;
			}
		}
	}
	void postorderA()
	{
		postorderAR(root);
	}

	void level_OrderAR(TNode* root)
	{
		if (root == NULL)
		{
			cout << "There is no Patient Record in Hospital Data" << endl;
			return;
		}

		queue<TNode*>q;
		q.push(root);

		while (!q.empty())
		{
			TNode* node = q.front();
			q.pop();
			if (node->record.status == 1)
			{
				cout << "Patient ID " << " " << ":";
				cout << node->record.patient_id;
				cout << endl;
				cout << "Patient name " << " " << ":";
				cout << node->record.patient_name;
				cout << endl;
				cout << "Patient admission date" << " " << ":";
				cout << node->record.admission_date;
				cout << endl;
				cout << "Patient disease diagnosis " << " " << ":";
				cout << node->record.disease_diagnosis;
				cout << endl;
				if (node->record.status == 1)
				{
					cout << "Patient Status :" << "Admitted" << endl;
				}
				else if (node->record.status == 0)
				{
					cout << "Patient Status :" << "Discharged" << endl;
				}

				cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
				cout << endl;
			}

			if (node->leftChild != NULL)
			{
				q.push(node->leftChild);
			}
			if (node->rightChild != NULL)
			{
				q.push(node->rightChild);
			}

		}
	}
	void level_OrderA()
	{
		level_OrderAR(root);
	}

	////Specific Patient Output

	TNode*orderSR(TNode* root, int id)
	{

		if (root == NULL)
		{
			cout << "Your Patient ID is not in Hospital Record" << endl;
			return root;
		}
		if (id == root->record.patient_id)
		{
			cout << "Patient ID " << " " << ":";
			cout << root->record.patient_id;
			cout << endl;
			cout << "Patient name " << " " << ":";
			cout << root->record.patient_name;
			cout << endl;
			cout << "Patient admission date" << " " << ":";
			cout << root->record.admission_date;
			cout << endl;
			cout << "Patient disease diagnosis " << " " << ":";
			cout << root->record.disease_diagnosis;
			cout << endl;
			if (root->record.status == 1)
			{
				cout << "Patient Status :" << "Admitted" << endl;
			}
			else if (root->record.status == 0)
			{
				cout << "Patient Status :" << "Discharged" << endl;
			}
			cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
			cout << endl;
			return root;
		}
		else if (id < root->record.patient_id)
		{
			return orderSR(root->leftChild, id);
		}
		else if (id > root->record.patient_id)
		{
			return orderSR(root->rightChild, id);
		}
		
		
		return root;
	}

	void orderS(int pat_record)
	{
		orderSR(root,pat_record);
	}


	////remove patient record

	TNode* find_mini(TNode* root)
	{
		while (root->leftChild != NULL)
		{
			root = root->leftChild;
		}
		return root;
	}

	TNode* removeR(TNode* root, int ID)
	{
		if (root == NULL)
		{
			cout << "Your Patient ID is not in Hospital Record" << endl;
			return root;
		}
		//doing search for same ID node

		if (ID < root->record.patient_id)        //left
		{
			root->leftChild = removeR(root->leftChild, ID);
		}
		else if (ID > root->record.patient_id)       //right
		{
			root->rightChild = removeR(root->rightChild, ID);
		}
		else  //ID == root->record.patient_id       //Found node,now delete it
		{
			if (root->leftChild == NULL && root->rightChild == NULL)     //No child
			{
				delete root;
				root = NULL;
			}
			else if (root->leftChild == NULL)          //one child ,no left child
			{
				TNode* temp = root;
				root = root->rightChild;
				delete temp;
			}
			else if (root->rightChild == NULL) //one chlid ,no right child
			{
				TNode* temp = root;
				root = root->leftChild;
				delete temp;
			}
			else                                      //both Child
			{
				TNode* temp = root->rightChild;
				temp = find_mini(temp);
				//left last node replace with root found node
				root->record.patient_id = temp->record.patient_id;
				root->record.patient_name = temp->record.patient_name;
				root->record.admission_date = temp->record.admission_date;
				root->record.disease_diagnosis = temp->record.disease_diagnosis;
				root->record.status = temp->record.status;
				//last left node delete because it moves to root found ID node
				root->rightChild = removeR(root->rightChild, temp->record.patient_id);

			}
		}
		return root;
	}
	void remove(int value)
	{
		root=removeR(root, value);
	}


	//total number of patients

	int sizePR(TNode* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		
		return 1 + sizePR(root->leftChild) + sizePR(root->rightChild);
		
	}
	int sizeP()
	{
		
		return sizePR(root);
		
	}


	///Edit Patient Record
	bool BSTcheckR(TNode* root, int min_value, int max_value)
	{
		if (root == NULL)
		{
			return true;
		}
		if (root->record.patient_id<min_value || root->record.patient_id>max_value) //violet rule
		{
			return false;
		}
		else
		{
			return(BSTcheckR(root->leftChild, min_value, root->record.patient_id - 1) && BSTcheckR(root->rightChild, root->record.patient_id + 1, max_value));
		}

	}
	bool BSTcheck()
	{
		return (BSTcheckR(root, INT_MIN, INT_MAX));  //smaller value than INT-MIN,large value than INT_MAX then violet BST
	}
	
	TNode* restoreR(TNode* root,PatientRecord record1)
	{
		if (root == NULL)
		{
			return new TNode(record1);
		}
		if (record1.patient_id < root->record.patient_id) //left
		{
		root->leftChild=	restoreR(root->leftChild, record1);
		}
		if (record1.patient_id > root->record.patient_id)     //right
		{
			root->rightChild=restoreR(root->rightChild, record1);
		}

		return root;

	}
	void  restore(PatientRecord record1)
	{
		root = restoreR(root, record1);
	}

	TNode* editPR(TNode* root, int id_p)
	{
		if (root == NULL)
		{
			cout << "This Patient ID is not in Hospital Data" << endl;
			return root;
		}
		if (id_p < root->record.patient_id) //left
		{
			return editPR(root->leftChild, id_p);
		}
		else if (id_p > root->record.patient_id) //right
		{
			return editPR(root->rightChild, id_p);
		}
		else if (id_p == root->record.patient_id)
		{
			int value = 10;
			int i = 0;
			int id;

			string name;
			string date;
			string disease;
			int status;
			cout << "If you want to edit patient ID : Press 1" << endl;;
			cout << "If you want to edit patient name : Press 2" << endl;;
			cout << "If you want to edit patient Admission Date : Press 3" << endl;;
			cout << "If you want to edit patient Disease Diagnosis : Press 4" << endl;;
			cout << "If you want to edit patient Status: Press 5" << endl;
			cout << "Stop Editing : Press 6" << endl;
			while (value != 6)
			{
				cout << "Press :";
				cin >> value;
				cin.ignore();
				cout << endl;
				if (value == 1)
				{
					i = 1;
					cout << "New Patient ID :";
					cin >> id;
					root->record.patient_id = id;
					cout << endl;

				}
				if (value == 2)
				{
					
					cout << "New Patient Name :";
					getline(cin, name);
					root->record.patient_name = name;
					cout << endl;
				}
				if (value == 3)
				{

					
					cout << "New Admission Date :";
					getline(cin, date);
					root->record.admission_date = date;
					cout << endl;

				}
				if (value == 4)
				{

					cout << "New Diseas Diagnosis :";
					getline(cin, disease);
					root->record.disease_diagnosis = disease;
					cout << endl;
				}
				if (value == 5)
				{

					cout << "Status(admitted:Press :1 / discharged: Press 0) :";
					cin >> status;
					root->record.status = status;
					cout << endl;
					

				}

			}
			if (i == 1)        //if patient id change needs rotation and check BST rules obey or not //tree form on base of patient ID's
			{
				bool result;
				result=BSTcheck();
				if (result)
				{
					cout << "After Edit the Patient Record the tree is still BST." << endl;

					return root;
				}
				else
				{
					cout << "After Edit the Patient Record the tree is not still BST.Therefore, we have to restore the BST property" << endl;

					int p_ID;
					string p_name;
					string p_date;
					string p_disease;
					int p_status;
					p_ID= root->record.patient_id;
					p_name = root->record.patient_name;
					p_disease = root->record.disease_diagnosis;
					p_date = root->record.admission_date;
					p_status = root->record.status;

					remove(p_ID);

					PatientRecord record1(p_ID, p_name, p_date, p_disease, p_status);
					restore(record1); 

					return root;


				}
				cout << endl;
				cout << "*********************************************************************************************************" << endl;
			
			}
		
			return root;
		}
		return root;
		
	}
	void editP(int id_p)
	{
		editPR(root, id_p);
	}

	
	/////Search Patient Record
	void moveNodeToLevel(TNode* node, int pid, int level,int k)
	{
		if (node == nullptr) 
		{
			return;
		}

		if (node->record.patient_id == pid)
		{
			moveNodeToLevelH(node, level,k);
		}
		else if (node->record.patient_id> pid) 
		{
			moveNodeToLevel(node->leftChild, pid, level,k);
		}
		else {
			moveNodeToLevel(node->rightChild, pid, level,k);
		}
	}

	void moveNodeToLevelH(TNode* node, int level,int k)
	{
		if (level<k)
		{
			return;
		}

		if (node->leftChild != nullptr) 
		{
			TNode* left = node->leftChild;
			node->leftChild = left->rightChild;
			left->rightChild = node;
			node = left;
		}

		if (node->rightChild != nullptr) 
		{
			TNode* right = node->rightChild;
			node->rightChild = right->leftChild;
			right->leftChild = node;
			node = right;
		}

		if (node->leftChild != nullptr) 
		{
			moveNodeToLevelH(node->leftChild, level - 1,k);
		}

		if (node->rightChild != nullptr)
		{
			moveNodeToLevelH(node->rightChild, level - 1,k);
		}
	}

	void moveL(int ID, int level,int k)
	{
		moveNodeToLevel(root, ID, level, k);
	}
	
	int level_pR(TNode* root, int id_p,int level_R)
	{

		if (root != NULL)
		{
			if (id_p < root->record.patient_id)
			{
				return (level_pR(root->leftChild, id_p, level_R + 1));
			}
			else if (id_p > root->record.patient_id)
			{
				return(level_pR(root->rightChild, id_p, level_R + 1));
			}
			else if (id_p == root->record.patient_id)
			{
				return level_R;
			}
		}
		return NULL;
			
	}
	int level_p(int id_p)
	{
		int level_R=0;
		return level_pR(root, id_p,level_R);
	}

	
	TNode* searchPR(TNode* root, int idSp)
	{
		if (root == NULL)
		{
			return root;
		}
		if (idSp < root->record.patient_id)   //left
		{
			return searchPR(root->leftChild, idSp);
		}
		else if (idSp > root->record.patient_id) //right
		{
			return searchPR(root->rightChild, idSp);
		}
		else if (idSp == root->record.patient_id)  //find
		{
			cout << "Search Patient Record is here " << endl;
			cout << endl;
			cout << "Patient ID " << " " << ":";
			cout << root->record.patient_id;
			cout << endl;
			cout << "Patient name " << " " << ":";
			cout << root->record.patient_name;
			cout << endl;
			cout << "Patient admission date" << " " << ":";
			cout << root->record.admission_date;
			cout << endl;
			cout << "Patient disease diagnosis " << " " << ":";
			cout << root->record.disease_diagnosis;
			cout << endl;
			if (root->record.status == 1)
			{
				cout << "Patient Status :" << "Admitted" << endl;
			}
			else if (root->record.status == 0)
			{
				cout << "Patient Status :" << "Discharged" << endl;
			}
			cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << endl;
			return root;
		}
		return root;
	}
	void searchP(int id_Sp,int k)
	{
		TNode* node;
		node=searchPR(root, id_Sp);

		
		if (node == NULL)
		{
			cout << "Your Patient ID " << " " << id_Sp << " " << "is not in Hospital Record" << endl;
			return;
		}

		int levelP;
		levelP = level_p(id_Sp);
		cout << "Search Patient ID :" << " " << id_Sp << " " << "is at Level " << " " << levelP;
		cout << endl;

		if (k > levelP)  //k large
		{
			cout << "Patient ID Record" << " " << id_Sp << " " << " is already at higher level than k.Therefore,No need of rotation"<<endl;
			return;
		}
		if (k == levelP)
		{
			cout << "Patient ID Record" << " " << id_Sp << " " << " is already at level k.Therefore,No need of rotation"  << endl;
			return;
		}
		if (k < levelP) //k small move root to k value upward
		{

			moveL(id_Sp, levelP,k);
			cout << "______________________________________Patient ID move at Desired Level___________________________________" << endl;
		}
		
		}
		

	
	/////Split Record

	void convertToLeftRightTrees(HospitalData& leftTree, HospitalData& rightTree) {
		convertToTrees(root, leftTree, rightTree);
	}

	void convertToTrees(TNode* node, HospitalData& leftTree, HospitalData& rightTree) {
		if (node == nullptr) {
			return;
		}

		// Insert the node into the appropriate tree
		if (node->leftChild != nullptr)
		{
			
			leftTree.insertAtRoot(node->leftChild->record);
			convertToTrees(node->leftChild, leftTree, rightTree);
		}

		if (node->rightChild != nullptr) {
			
			rightTree.insertAtRoot(node->rightChild->record);
			convertToTrees(node->rightChild, leftTree, rightTree);
		}
	}
	TNode* find_median(TNode* root, int& count, int& median)      //middle value find by traversing like inorder
	{

		if (root == NULL)
		{
			return NULL;
		}
		TNode* left = find_median(root->leftChild, count, median);

		if (left != NULL)
		{
			return left;
		}

		count++; //count till reach middle value

		if (count == median + 1)     //find middle value
		{
			return root;
		}
		return (find_median(root->rightChild, count, median));

	}
	void rightP()
	{
		inorderR(root->rightChild);
	}
	void leftP()
	{
		inorderR(root->leftChild);
	}
	TNode* splitbstR(TNode* root)
	{
		int total_nodes = sizeP();
		int median = total_nodes / 2;
		int count = 0;

		TNode* middle_Node = find_median(root, count, median);
		cout << "Middle Patient Record " << endl;
		cout << "Patient ID :" << middle_Node->record.patient_id << endl;
		cout<<"Patient Name :"<< middle_Node->record.patient_name<<endl;
		cout << "Patient Disease :" << middle_Node->record.disease_diagnosis << endl;;
		cout<<"Patient Admission Date :"<< middle_Node->record.admission_date<<endl;
	
		if (middle_Node->record.status == 1)
		{
			cout << "Patient status : Admitted" << endl;
		}
		else
		{
			cout << "Patient status : discharged" << endl;
		}

		int id_S = middle_Node->record.patient_id;
		int level_SP=level_p(id_S);
		int k = 0;
		
		int p_ID;
		string p_name;
		string p_date;
		string p_disease;
		int p_status;
		p_ID = middle_Node->record.patient_id;
		p_name = middle_Node->record.patient_name;
		p_disease = middle_Node->record.disease_diagnosis;
		p_date = middle_Node->record.admission_date;
		p_status = middle_Node->record.status;

		remove(p_ID);
		PatientRecord record1(p_ID, p_name, p_date, p_disease, p_status);
		insertAtRoot(record1);

		cout << "*********************************************Display Middle Node at Root ******************************************" << endl;
		cout << endl;
		cout << "------InOrder Display------" << endl;
		inorder();
		cout << endl;
		cout << endl;

		cout << "------Level Order Display------" << endl;
		level_Order();
		cout << endl;
		cout << endl;
		
		cout << "************************Tree Value greater than Middle node*************************" << endl;
		cout << endl;
		rightP();
		cout << "************************Tree Value less than Middle node*************************" << endl;
		cout << endl;
		leftP();
	
		return root;
	}
	void splitbst()
	{
		root = splitbstR(root);
	
	}


};


int main()
{

	int ID;
	int find_ID;
	string name;
	string date;
	string disease;
	int status;
	int record;
	int p_ID;
	int search_id;
	int k;

	HospitalData HD;

	HospitalData lefttree;
	HospitalData righttree;
	int input = 20;

	cout << "1:Insert Patient Record" << endl;
	cout << "2:Check Tree is BST" << endl;
	cout << "3:Edit Patient Record" << endl;
	cout << "4:Remove Patient Record" << endl;
	cout << "5:Search Patient Record" << endl;
	cout << "6:Split Patient Record" << endl;
	cout << "7:Display of All Patients Records" << endl;
	cout << "8:Display of Admitted Patients Records" << endl;                          //admitted/discharged
	cout << "9:Display of Specific Patient Record" << endl;
	cout << "10:Total Numbers of Patients in Hospital" << endl;
	cout << "11:To End the Program" << endl;


	while (input != 25)
	{

		cout << "Enter :";
		cin >> input;
		cout << endl;

		switch (input)
		{

		case 1:
		{
			cout << "---------------------------------------------Insert-----------------------------------------------" << endl;
			cout << endl;

			cout << "Enter Patient ID" << " " << " :";
			cin >> ID;
			cin.ignore();             //after int input use getline
			cout << endl;

			cout << "Enter Patient Name" << " " << ":";
			getline(cin, name);
			cin.clear();
			cout << endl;
			cout << "Enter Patient Admission Date" << " " << ":";
			getline(cin, date);
			cin.clear();
			cout << endl;
			cout << "Enter Patient Disease Diagnosis" << " " << ":";
			getline(cin, disease);
			cin.clear();
			cout << endl;
			cout << "Enter Patient Status" << endl;
			cout << "Press 1 for Admitted or Press 0 for Discharged" << "  " << ":";
			cin >> status;
			cin.clear();
			cin.ignore();
			cout << endl;

			PatientRecord record(ID, name, date, disease, status);   //record is  instance of patient record class
			HD.insertAtRoot(record);

			cout << endl;
			cout << endl;
			break;

		}
		case 2:
		{
			cout << "-----------------------------------------------Check tree is BST-----------------------------------------------" << endl;
			cout << endl;
			bool result;
			result = HD.BSTcheck();
			if (result)
			{
				cout << "Tree Is BST." << endl;

			}
			else
			{
				cout << "Tree is not BST" << endl;
			}

			cout << endl;
			cout << endl;
			break;
		}
		case 3:
		{
			cout << "--------------------------------------Edit Patient Record-------------------------------------" << endl;
			cout << endl;
			cout << "Enter the patient ID which you want to Edit" << endl;
			cin >> p_ID;
			HD.editP(p_ID);
			cout << endl;
			cout << endl;
			break;

		}
		case 4:
		{
			cout << "--------------------------------------Delete Patient Record--------------------------------------" << endl;
			cout << endl;
			cout << "Enter the Patient ID you want to delete from Hospital Record" << endl;
			cin >> find_ID;
			HD.remove(find_ID);
			cout << endl;
			cout << endl;
			break;

		}
		case 5:
		{
			cout << "-------------------------------------Search Patient Record----------------------------------------" << endl;
			cout << endl;
			cout << "Enter the Patient ID which you want to Search" << endl;
			cin >> search_id;
			cout << endl;
			cout << "Enter the k value where you want to move your Patient ID :" << endl;
			cin >> k;
			cout << endl;
			HD.searchP(search_id, k);
			cout << endl;
			cout << endl;
			break;
		}
		case 6:
		{
			cout << "--------------------------------------Split patient Record-----------------------------------------" << endl;
			cout << endl;
			HD.splitbst();

			HD.convertToLeftRightTrees(lefttree, righttree);
			
			lefttree.inorder();
			righttree.inorder();
			cout << endl;

			

			cout << endl;
			
			
			cout << endl;
			cout << endl;
			break;

		}
		case 7:
		{
			cout << "--------------------------------------Display of All Patients Records-------------------------------------" << endl;
			cout << endl;
			cout << endl;
			cout << "-------------------------------------------Inorder Traversal---------------------------------------------" << endl;
			HD.inorder();
			cout << endl;
			cout << endl;

			cout << "-----------------------------------------Preorder Traversal-----------------------------------------------" << endl;
			HD.preorder();
			cout << endl;
			cout << endl;


			cout << "------------------------------------------Postorder Traversal----------------------------------------" << endl;
			HD.postorder();
			cout << endl;
			cout << endl;

			cout << "----------------------------------------Level Order Traversal--------------------------------------------" << endl;
			HD.level_Order();
			cout << endl;
			cout << endl;
			break;

		}
		case 8:
		{
			cout << "-------------------------------------Display of Admitted Patients Records------------------------------------------" << endl;
			cout << endl;
			cout << endl;
			cout << "----------------------------------------------Inorder Traversal-----------------------------------------------" << endl;
			HD.inorderA();
			cout << endl;
			cout << endl;

			cout << "---------------------------------------------Preorder Traversal------------------------------------------------" << endl;
			HD.preorderA();
			cout << endl;
			cout << endl;


			cout << "---------------------------=------------------Postorder Traversal----------------------------------------------" << endl;
			HD.postorderA();
			cout << endl;
			cout << endl;

			cout << "---------------------------------------------Level Order Traversal----------------------------------------------" << endl;
			HD.level_OrderA();
			cout << endl;
			cout << endl;
			break;


		}
		case 9:
		{

			cout << "-------------------------------------Display of Specific Patient Record-------------------------------------------" << endl;
			cout << endl;
			cout << endl;
			cout << "Enter the Patient ID to see its Record " << endl;
			cin >> record;
			cout << endl;
			cout << endl;
			HD.orderS(record);
			cout << endl;
			cout << endl;

			break;
		}
		case 10:
		{
			cout << "-----------------------Total Numbers of Patients Record in Hospital Data--------------------------" << endl;
			cout << endl;
			int sizeD;
			sizeD = HD.sizeP();
			cout << "Total" << " " << ":" << sizeD;
			cout << endl;
			cout << endl;
			break;
		}
		case 11:
		{
			cout << "Your Program is End :)" << endl;
			input = 25;
			return 0;
		}
		default:
		{
			cout << "You enter the wrong input" << endl;
			cout << endl;
			break;
		}
		}
	}

	return 0;

}
