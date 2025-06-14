class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        nge = {}  # dictionary to map number to its next greater
        st = []

        for num in reversed(nums2):
            while st and st[-1] <= num:
                st.pop()
            if st:
                nge[num] = st[-1]
            else:
                nge[num] = -1
            st.append(num)

        # Build answer using the map
        ans = []
        for num in nums1:
            ans.append(nge[num])
        return ans
