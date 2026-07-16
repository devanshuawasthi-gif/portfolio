class Solution(object):
    def pairSum(self, head):
        slow = head
        fast = head
        #find middle 
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            #reverse second half
        prev = None
        curr = slow
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
            #find maximum
        ans = 0
        first = head
        second = prev
        while second:
            ans = max(ans, first.val + second.val)
            first = first.next
            second = second.next
        return ans     