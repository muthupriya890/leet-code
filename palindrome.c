bool isPalindrome(int x) {
    
    if (x < 0) {
        return false;
    }
    
    long original = x;
    long reversed = 0;
    
    
    while (x > 0) {
        int remainder = x % 10;
        reversed = (reversed * 10) + remainder;
        x = x / 10;
    }
    
    
    if (original == reversed) {
        return true;
    } else {
        return false;
    }
}
