class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        chef_end = 0
        total_wait = 0
        for i in range(len(customers)):
            arrival, time = customers[i][0], customers[i][1]
            chef_start = max(chef_end, arrival)
            chef_end = chef_start + time
            total_wait += chef_end - arrival

        avg = total_wait / len(customers)
        return avg


        