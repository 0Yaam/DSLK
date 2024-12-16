struct SinhVien
{
	string maSV;
	string hoSV;
	string tenLot;
	string ten;
	int namSinh;
};
typedef SinhVien nodeData;
struct tagNode
{
	nodeData info;
	tagNode* pNext;
};
typedef tagNode Node;


struct List
{
	Node* pHead;
	Node* pTail;
};


void CreateList(List& l)
{
	l.pHead = l.pTail = NULL;
}

Node* GetNode(nodeData x)
{
	Node* p = new Node;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
	}

	return p;
}


void InsertTail(List& l, nodeData x)
{
	Node* p = GetNode(x);
	if (p == NULL)
		return;

	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}


void InsertHead(List& l, nodeData x)
{
	Node* p = GetNode(x);
	if (p == NULL)
		return;

	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

bool IsEmpty(List& l)
{
	return l.pHead == NULL;
}
int DocFile(List& l, string filename)
{
	fstream in(filename);
	if (!in)
		return 0;
	CreateList(l);
	nodeData x;
	while (!in.eof())
	{
		in >> x.maSV;
		in >> x.hoSV;
		in >> x.tenLot;
		in >> x.ten;
		in >> x.namSinh;

		InsertTail(l, x);
	}in.close();
	return 1;
}

void TieuDe()
{
	for (int i = 0; i < 70; i++)
	{
		cout << "=";
	}
	cout<<setiosflags(ios::left)<<endl<<
		setw(10) << "Ma SV" <<
		setw(10) << "Ho" <<
		setw(10) << "Ten lot" <<
		setw(10) << "Ten" <<
		setw(10) << "NamSinh"  << endl;

	for (int i = 0; i < 70; i++)
	{
		cout << "=" ;
	}cout << endl;
}
void Xuat1SV(nodeData p)
{
	cout << setiosflags(ios::left) <<
		setw(10) << p.maSV <<
		setw(10) << p.hoSV <<
		setw(10) << p.tenLot <<
		setw(10) << p.ten <<
		setw(10) << p.namSinh << endl;
}


void XuatDSSV(List l)
{
	TieuDe();
	for (Node *p = l.pHead; p!= NULL; p = p->pNext)
	{
		Xuat1SV(p->info);
	}

	for (int i = 0; i < 70; i++)
	{
		cout << "=";
	}cout << endl;
}



int DemSLNamSinh(List& l, int namSinh)
{
	int dem = 0;
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->info.namSinh >= namSinh)
			dem++;
	}
	return dem;
}


Node* TKTT(List l, string tenCanTim)
{
	Node* q = NULL;
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->info.ten == tenCanTim)
			q = p;
	}
	return q;
}


Node* Nhap1SV()
{
	nodeData x;
	cout << "Nhap mssv: "; cin >> x.maSV;
	cout << "Nhap ho: "; cin >> x.hoSV;
	cout << "Nhap ten lot: "; cin >> x.tenLot;
	cout << "Nhap ten: "; cin >> x.ten;
	cout << "Nhap nam sinh: "; cin >> x.namSinh;
	return GetNode(x);
}

Node* TimNhanVien(List l, string maCanTim) {
	for (Node* p = l.pHead; p != NULL; p = p->pNext) {
		if (p->info.maSV == maCanTim)
			return p;
	}

	return nullptr;
}

void Chen(List& l, string maNV) {
	Node* q = TimNhanVien(l, maNV);
	if (q == nullptr) {
		cout << "Khong tim thay ma sinh vien: " << maNV << endl;
		return exit(EXIT_FAILURE);
	}
	Node* p = Nhap1SV();
	for (Node* r = l.pHead; r != NULL; r = r->pNext)
	{
		if (p->info.maSV.length() < 7 || p->info.maSV == r->info.maSV)
		{
			cout << "Ma sinh vien khong hop le!" << endl;
			return exit(EXIT_FAILURE);
		}

	}

	if (q == l.pTail) 
	{ 
		InsertTail(l, p->info);
		return;
	}

	p->pNext = q->pNext;
	q->pNext = p;
}


Node* TimKiemLinhCanh(List l, string tenCT)
{
	if (IsEmpty(l))return NULL;
	Node* lc = new Node;
	Node* prev = l.pTail;
	lc->info.ten = tenCT;
	InsertTail(l, lc->info);
	for (Node* p = l.pHead; p != NULL;)
	{
		if (p->info.ten != lc->info.ten)
		{
			p = p->pNext;
			if (p == lc)
				return NULL;
		}
		else
		{
			l.pTail = prev;
			l.pTail->pNext = NULL;
			return p;
		}

	}
}
Node* Mid(Node* left, Node* right)
{
	Node* turtle = left;
	Node* rabbit = left;
	while (rabbit != right && rabbit->pNext != right)
	{
		turtle = turtle->pNext;
		rabbit = rabbit->pNext->pNext;
	}
	return turtle;
}

Node* BinarySearch(List l, string maCT)
{
	
	Node* left = l.pHead;
	Node* right = NULL;
	Node* mid;
	while (left != right)
	{
		mid = Mid(left, right);
		if (mid->info.maSV == maCT)
			return mid;
		if (mid->info.maSV > maCT)
			right = mid;
		else
		{
			left = mid->pNext;
		}
	}
	return NULL;
}


void ThongKe(List l)
{
	map<int, int> thongke;
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		thongke[p->info.namSinh]++;
	}

	for (auto item : thongke)
	{
		cout << item.first << "\t" << item.second << " sinh vien"<<endl;
	}
}

void InsertSort(List& l)
{
	List l2;
	CreateList(l2);
	while (l.pHead != NULL)
	{
		Node* p = l.pHead;
		l.pHead = l.pHead->pNext;
		p->pNext = NULL;
			if (l2.pHead == NULL || l2.pHead->info.namSinh > p->info.namSinh)
				InsertHead(l2, p->info);
			else
			{
				Node* q = l2.pHead;
				while (q->pNext != NULL && p->info.namSinh >= q->pNext->info.namSinh)
					q = q->pNext;

				p->pNext = q->pNext;
				q->pNext = p;
				if (p->pNext == NULL)
					l.pTail = p;
			}
	 }
	l = l2;
}


void Xoa(List& l, string ten)
{
	Node* prev = NULL;
	for (Node* p = l.pHead; p != NULL;)
	{
		if (p->info.ten == ten)
		{
			Node* temp = p;
			p = p->pNext;
			if (temp == l.pHead)
			{
				l.pHead = l.pHead->pNext;
				
			}
			else
			{
				prev->pNext = temp->pNext;
				if (temp->pNext == NULL)
					l.pTail = prev;
			}
			delete temp;
		}
		else
		{
			prev = p;
			p = p->pNext;
		}

	}
}

int GetMaxYear(List l)
{
	int max = l.pHead->info.namSinh;
	for (Node* p = l.pHead->pNext; p != NULL; p = p->pNext)
	{
		if (p->info.namSinh > max)
			max = p->info.namSinh;
	}
	return max;
}


void CollectionBuckets(vector<List>& buckets, List& l)
{
	CreateList(l);
	for (int i = 0; i < buckets.size(); i++)
	{
		if(buckets[i].pHead != NULL) {
			if (l.pHead == NULL)
			{
				l.pHead = buckets[i].pHead;
				l.pTail = buckets[i].pTail;
			}
			else
			{
				l.pTail->pNext = buckets[i].pHead;
				l.pTail = buckets[i].pTail;
			}
		}
		CreateList(buckets[i]);
	}
}


void RadixSort(List& l)
{
	if (l.pHead == NULL || l.pHead->pNext == NULL) return;
	int max = GetMaxYear(l);
	int unit = 1;

	vector<List> buckets(10);
	while (max / unit > 0)
	{
		for (Node* p = l.pHead; p != NULL; p = p->pNext)
		{
			int value = (p->info.namSinh / unit) % 10;
			InsertTail(buckets[value], p->info);
		}
		CollectionBuckets(buckets, l);
		unit *= 10;
	}

}