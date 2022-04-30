#/*
# * 1396. Design Underground System
# *
# * https://leetcode.com/problems/design-underground-system/
# * 
# * Runtime: 365 ms (31.36% Better)
# * Memory Usage: 25.1 MB (42.94% Better than)
# */

class UndergroundSystem:

    def __init__(self):
      self.customers = dict()
      self.station_path = dict()
        

    def checkIn(self, id: int, stationName: str, t: int) -> None:
      self.customers[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
      customer = self.customers.get(id)
      link = f"{customer[0]}-{stationName}"
      station = self.station_path.get(link, None)
      if station is None:
        new = (1, (t - customer[1]))
      else:
        new = (station[0]+1, station[1]+ (t - customer[1]))
      self.station_path[link] = new

    def getAverageTime(self, startStation: str, endStation: str) -> float:
      link = f"{startStation}-{endStation}"
      station = self.station_path[link]
      return (float(station[1]) / float(station[0]))
        


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)
