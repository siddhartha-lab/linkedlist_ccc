// Linked List Node Class
class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
        this.address = this.generateAddress();
    }
    
    generateAddress() {
        // Generate a simulated memory address (hexadecimal)
        return '0x' + Math.floor(Math.random() * 0xFFFF).toString(16).toUpperCase().padStart(4, '0');
    }
}

// Linked List Class
class LinkedList {
    constructor() {
        this.head = null;
        this.size = 0;
    }
    
    // Insert at beginning - O(1)
    insertAtBeginning(data) {
        const newNode = new Node(data);
        addLog(`Creating new node with data: ${data}`, 'info');
        addLog(`Node address: ${newNode.address}`, 'info');
        
        if (this.head === null) {
            this.head = newNode;
            addLog(`List was empty. Setting head = ${newNode.address}`, 'success');
        } else {
            addLog(`Setting newNode.next = head (${this.head.address})`, 'info');
            newNode.next = this.head;
            addLog(`Updating head = newNode (${newNode.address})`, 'info');
            this.head = newNode;
        }
        
        this.size++;
        addLog(`✓ Insert at beginning completed. Size: ${this.size}`, 'success');
        return newNode;
    }
    
    // Insert at end - O(n)
    insertAtEnd(data) {
        const newNode = new Node(data);
        addLog(`Creating new node with data: ${data}`, 'info');
        addLog(`Node address: ${newNode.address}`, 'info');
        
        if (this.head === null) {
            this.head = newNode;
            addLog(`List was empty. Setting head = ${newNode.address}`, 'success');
        } else {
            addLog(`Traversing to find last node...`, 'info');
            let temp = this.head;
            let position = 1;
            
            while (temp.next !== null) {
                addLog(`At position ${position}: ${temp.address} → next exists`, 'info');
                temp = temp.next;
                position++;
            }
            
            addLog(`Found last node at position ${position}: ${temp.address}`, 'info');
            addLog(`Setting temp.next = newNode (${newNode.address})`, 'info');
            temp.next = newNode;
        }
        
        this.size++;
        addLog(`✓ Insert at end completed. Size: ${this.size}`, 'success');
        return newNode;
    }
    
    // Insert at position - O(n)
    insertAtPosition(data, position) {
        if (position < 1 || position > this.size + 1) {
            addLog(`✗ Invalid position ${position}. Valid range: 1 to ${this.size + 1}`, 'error');
            return null;
        }
        
        if (position === 1) {
            return this.insertAtBeginning(data);
        }
        
        const newNode = new Node(data);
        addLog(`Creating new node with data: ${data} at position ${position}`, 'info');
        addLog(`Node address: ${newNode.address}`, 'info');
        
        let temp = this.head;
        let currentPos = 1;
        
        addLog(`Traversing to position ${position - 1}...`, 'info');
        while (currentPos < position - 1) {
            addLog(`At position ${currentPos}: ${temp.address}`, 'info');
            temp = temp.next;
            currentPos++;
        }
        
        addLog(`Reached position ${currentPos}: ${temp.address}`, 'info');
        addLog(`Setting newNode.next = temp.next (${temp.next ? temp.next.address : 'NULL'})`, 'info');
        newNode.next = temp.next;
        addLog(`Setting temp.next = newNode (${newNode.address})`, 'info');
        temp.next = newNode;
        
        this.size++;
        addLog(`✓ Insert at position ${position} completed. Size: ${this.size}`, 'success');
        return newNode;
    }
    
    // Delete first node - O(1)
    deleteFirst() {
        if (this.head === null) {
            addLog(`✗ Cannot delete: List is empty`, 'error');
            return null;
        }
        
        const deletedNode = this.head;
        addLog(`Deleting first node: ${deletedNode.address} (data: ${deletedNode.data})`, 'warning');
        addLog(`temp = head (${this.head.address})`, 'info');
        addLog(`head = head.next (${this.head.next ? this.head.next.address : 'NULL'})`, 'info');
        
        this.head = this.head.next;
        this.size--;
        
        addLog(`Freeing memory at ${deletedNode.address}`, 'warning');
        addLog(`✓ Delete first completed. Size: ${this.size}`, 'success');
        return deletedNode;
    }
    
    // Delete last node - O(n)
    deleteLast() {
        if (this.head === null) {
            addLog(`✗ Cannot delete: List is empty`, 'error');
            return null;
        }
        
        if (this.head.next === null) {
            return this.deleteFirst();
        }
        
        addLog(`Traversing to find second-to-last node...`, 'info');
        let temp = this.head;
        let position = 1;
        
        while (temp.next.next !== null) {
            addLog(`At position ${position}: ${temp.address}`, 'info');
            temp = temp.next;
            position++;
        }
        
        const deletedNode = temp.next;
        addLog(`Found second-to-last at position ${position}: ${temp.address}`, 'info');
        addLog(`Last node: ${deletedNode.address} (data: ${deletedNode.data})`, 'warning');
        addLog(`Setting temp.next = NULL`, 'info');
        
        temp.next = null;
        this.size--;
        
        addLog(`Freeing memory at ${deletedNode.address}`, 'warning');
        addLog(`✓ Delete last completed. Size: ${this.size}`, 'success');
        return deletedNode;
    }
    
    // Delete at position - O(n)
    deleteAtPosition(position) {
        if (this.head === null) {
            addLog(`✗ Cannot delete: List is empty`, 'error');
            return null;
        }
        
        if (position < 1 || position > this.size) {
            addLog(`✗ Invalid position ${position}. Valid range: 1 to ${this.size}`, 'error');
            return null;
        }
        
        if (position === 1) {
            return this.deleteFirst();
        }
        
        addLog(`Deleting node at position ${position}...`, 'warning');
        let temp = this.head;
        let currentPos = 1;
        
        while (currentPos < position - 1) {
            addLog(`At position ${currentPos}: ${temp.address}`, 'info');
            temp = temp.next;
            currentPos++;
        }
        
        const deletedNode = temp.next;
        addLog(`Found node before deletion point at position ${currentPos}: ${temp.address}`, 'info');
        addLog(`Node to delete: ${deletedNode.address} (data: ${deletedNode.data})`, 'warning');
        addLog(`Setting temp.next = temp.next.next (${deletedNode.next ? deletedNode.next.address : 'NULL'})`, 'info');
        
        temp.next = temp.next.next;
        this.size--;
        
        addLog(`Freeing memory at ${deletedNode.address}`, 'warning');
        addLog(`✓ Delete at position ${position} completed. Size: ${this.size}`, 'success');
        return deletedNode;
    }
    
    // Search for a value - O(n)
    search(value) {
        if (this.head === null) {
            addLog(`✗ Cannot search: List is empty`, 'error');
            return -1;
        }
        
        addLog(`Searching for value: ${value}...`, 'info');
        let temp = this.head;
        let position = 1;
        
        while (temp !== null) {
            addLog(`Position ${position} (${temp.address}): Comparing ${temp.data}... ${temp.data === value ? 'MATCH!' : 'no'}`, 
                   temp.data === value ? 'success' : 'info');
            
            if (temp.data === value) {
                addLog(`✓ Found ${value} at position ${position}`, 'success');
                return position;
            }
            
            temp = temp.next;
            position++;
        }
        
        addLog(`✗ Value ${value} not found in list`, 'error');
        return -1;
    }
    
    // Traverse the list - O(n)
    traverse() {
        if (this.head === null) {
            addLog(`List is empty - nothing to traverse`, 'warning');
            return [];
        }
        
        addLog(`Starting traversal from head...`, 'info');
        let temp = this.head;
        let position = 1;
        const nodes = [];
        
        while (temp !== null) {
            const nextAddr = temp.next ? temp.next.address : 'NULL';
            addLog(`Position ${position}: [${temp.address} | ${temp.data} | next → ${nextAddr}]`, 'info');
            nodes.push(temp);
            temp = temp.next;
            position++;
        }
        
        addLog(`✓ Traversal completed. Total nodes: ${this.size}`, 'success');
        return nodes;
    }
    
    // Get all nodes as array
    toArray() {
        const result = [];
        let temp = this.head;
        while (temp !== null) {
            result.push(temp);
            temp = temp.next;
        }
        return result;
    }
}

// Global variables
let linkedList = new LinkedList();
let animationSpeed = 1.0;

// Initialize
document.addEventListener('DOMContentLoaded', () => {
    updateVisualization();
});

// Update animation speed
function updateSpeed(value) {
    animationSpeed = parseFloat(value);
    document.getElementById('speedValue').textContent = value + 'x';
}

// Add log entry
function addLog(message, type = 'info') {
    const logContainer = document.getElementById('logContainer');
    const logEntry = document.createElement('div');
    logEntry.className = `log-entry log-${type}`;
    
    const time = new Date().toLocaleTimeString();
    logEntry.innerHTML = `
        <span class="log-time">${time}</span>
        <span class="log-message">${message}</span>
    `;
    
    logContainer.appendChild(logEntry);
    logContainer.scrollTop = logContainer.scrollHeight;
}

// Clear log
function clearLog() {
    const logContainer = document.getElementById('logContainer');
    logContainer.innerHTML = `
        <div class="log-entry log-info">
            <span class="log-time">${new Date().toLocaleTimeString()}</span>
            <span class="log-message">Log cleared.</span>
        </div>
    `;
}

// Update visualization
function updateVisualization() {
    const container = document.getElementById('linkedListContainer');
    const nodes = linkedList.toArray();
    
    // Update info badges
    document.getElementById('nodeCount').textContent = linkedList.size;
    document.getElementById('headAddress').textContent = linkedList.head ? linkedList.head.address : 'NULL';
    
    if (nodes.length === 0) {
        container.innerHTML = `
            <div class="empty-state">
                <div class="empty-icon">📋</div>
                <p>Linked List is empty</p>
                <p class="empty-hint">Start by inserting a node</p>
            </div>
        `;
        return;
    }
    
    container.innerHTML = '';
    
    nodes.forEach((node, index) => {
        // Create node element
        const nodeDiv = document.createElement('div');
        nodeDiv.className = 'node';
        nodeDiv.innerHTML = `
            <div class="node-box">
                <div class="node-address">Address: ${node.address}</div>
                <div class="node-data">${node.data}</div>
                <div class="node-next">next: ${node.next ? node.next.address : 'NULL'}</div>
            </div>
        `;
        
        container.appendChild(nodeDiv);
        
        // Add arrow if not last node
        if (index < nodes.length - 1) {
            const arrow = document.createElement('div');
            arrow.className = 'arrow';
            arrow.textContent = '→';
            container.appendChild(arrow);
        }
    });
    
    // Add NULL indicator
    const nullDiv = document.createElement('div');
    nullDiv.className = 'null-indicator';
    nullDiv.textContent = 'NULL';
    container.appendChild(nullDiv);
}

// Insert at beginning
async function insertAtBeginning() {
    const input = document.getElementById('insertValue');
    const value = parseInt(input.value);
    
    if (isNaN(value)) {
        addLog('✗ Please enter a valid number', 'error');
        return;
    }
    
    addLog(`=== INSERT AT BEGINNING: ${value} ===`, 'info');
    linkedList.insertAtBeginning(value);
    
    await sleep(500 / animationSpeed);
    updateVisualization();
    
    input.value = '';
}

// Insert at end
async function insertAtEnd() {
    const input = document.getElementById('insertEndValue');
    const value = parseInt(input.value);
    
    if (isNaN(value)) {
        addLog('✗ Please enter a valid number', 'error');
        return;
    }
    
    addLog(`=== INSERT AT END: ${value} ===`, 'info');
    linkedList.insertAtEnd(value);
    
    await sleep(500 / animationSpeed);
    updateVisualization();
    
    input.value = '';
}

// Insert at position
async function insertAtPosition() {
    const valueInput = document.getElementById('insertPosValue');
    const posInput = document.getElementById('insertPosition');
    const value = parseInt(valueInput.value);
    const position = parseInt(posInput.value);
    
    if (isNaN(value) || isNaN(position)) {
        addLog('✗ Please enter valid numbers for both value and position', 'error');
        return;
    }
    
    addLog(`=== INSERT AT POSITION: ${value} at position ${position} ===`, 'info');
    linkedList.insertAtPosition(value, position);
    
    await sleep(500 / animationSpeed);
    updateVisualization();
    
    valueInput.value = '';
    posInput.value = '';
}

// Delete first
async function deleteFirst() {
    addLog(`=== DELETE FIRST NODE ===`, 'warning');
    const deleted = linkedList.deleteFirst();
    
    if (deleted) {
        await sleep(500 / animationSpeed);
        updateVisualization();
    }
}

// Delete last
async function deleteLast() {
    addLog(`=== DELETE LAST NODE ===`, 'warning');
    const deleted = linkedList.deleteLast();
    
    if (deleted) {
        await sleep(500 / animationSpeed);
        updateVisualization();
    }
}

// Delete at position
async function deleteAtPosition() {
    const posInput = document.getElementById('deletePosition');
    const position = parseInt(posInput.value);
    
    if (isNaN(position)) {
        addLog('✗ Please enter a valid position', 'error');
        return;
    }
    
    addLog(`=== DELETE AT POSITION: ${position} ===`, 'warning');
    linkedList.deleteAtPosition(position);
    
    await sleep(500 / animationSpeed);
    updateVisualization();
    
    posInput.value = '';
}

// Search value
async function searchValue() {
    const input = document.getElementById('searchValue');
    const value = parseInt(input.value);
    
    if (isNaN(value)) {
        addLog('✗ Please enter a valid number to search', 'error');
        return;
    }
    
    addLog(`=== SEARCH: ${value} ===`, 'info');
    const position = linkedList.search(value);
    
    if (position !== -1) {
        // Highlight the found node
        const nodes = document.querySelectorAll('.node-box');
        if (nodes[position - 1]) {
            nodes[position - 1].classList.add('node-highlight');
            setTimeout(() => {
                nodes[position - 1].classList.remove('node-highlight');
            }, 2000 / animationSpeed);
        }
    }
    
    input.value = '';
}

// Traverse list
async function traverseList() {
    addLog(`=== TRAVERSE LIST ===`, 'info');
    linkedList.traverse();
}

// Clear list
function clearList() {
    if (confirm('Are you sure you want to clear the entire list?')) {
        addLog(`=== CLEARING LIST ===`, 'warning');
        linkedList = new LinkedList();
        updateVisualization();
        addLog(`✓ List cleared successfully`, 'success');
    }
}

// Utility function for delays
function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}
