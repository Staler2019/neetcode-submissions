public class Solution {
    public int CarFleet(int target, int[] position, int[] speed) {
        var ordered = position.Zip(speed, (posi, speed) => (Position: posi, Speed: speed)).OrderByDescending(x => x.Position);
        double lastCarMaxTime = 0;
        int fleetCount = 0;

        foreach (var car in ordered)
        {
            double currentCarTime = (double)(target - car.Position) / car.Speed;

            if (currentCarTime > lastCarMaxTime)
            {
                lastCarMaxTime = currentCarTime;
                fleetCount++;
            }
        }

        return fleetCount;
    }
}
