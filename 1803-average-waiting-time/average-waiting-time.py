class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        chef_end, total_wait = 0, 0
        for arrival, time in customers:
            if arrival > chef_end:
                chef_end = arrival
            chef_end += time
            total_wait += chef_end - arrival
        avg = total_wait / len(customers)
        return avg


        