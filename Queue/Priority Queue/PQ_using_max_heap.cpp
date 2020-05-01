#include<vector>
class PriorityQueue {
    // Complete this class
    	vector<int> pq;

	public :

	PriorityQueue() {

	}

	bool isEmpty() {
		return pq.size() == 0;
	}

	// Return the size of priorityQueue - no of elements present
	int getSize() {
		return pq.size();
	}

	int getMax() {
		if(isEmpty()) {
			return 0;		// Priority Queue is empty
		}
		return pq[0];
	}

	void insert(int element) {
		pq.push_back(element);
		
		int childIndex = pq.size() - 1;

		while(childIndex > 0) {
			int parentIndex = (childIndex - 1) / 2;

			if(pq[childIndex] > pq[parentIndex]) {
				int temp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];
				pq[parentIndex] = temp;
			}
			else {
				break;
			}
			childIndex = parentIndex;
		}

	}

	int removeMax() {
		if(isEmpty()) {
			return 0;		// Priority Queue is empty
		}
		int ans = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();

		// up-heapify

		int parentIndex = 0;
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndx = 2 * parentIndex + 2;
	
		while(leftChildIndex < pq.size()) {
			int maxIndex = parentIndex;
			if(pq[maxIndex] < pq[leftChildIndex]) {
				maxIndex = leftChildIndex;
			}
			if(rightChildIndx < pq.size() && pq[rightChildIndx] > pq[maxIndex]) {
				maxIndex = rightChildIndx;
			}
			if(maxIndex == parentIndex) {
				break;
			}
			int temp = pq[maxIndex];
			pq[maxIndex] = pq[parentIndex];
			pq[parentIndex] = temp;
		
			parentIndex = maxIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndx = 2 * parentIndex + 2;
		}

		return ans;



	}
    
};