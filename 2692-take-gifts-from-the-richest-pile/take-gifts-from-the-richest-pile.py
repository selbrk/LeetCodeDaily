class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        gifts = [-gift for gift in gifts]
        heapq.heapify(gifts)
        while k:
            gift = -1 * heapq.heappop(gifts)
            print(gift)
            gift = math.floor(math.sqrt(gift))
            heapq.heappush(gifts, -gift)
            k-=1
        
        return -sum(gifts)

        