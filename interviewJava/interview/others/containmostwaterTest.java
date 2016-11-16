package others;

import static org.junit.Assert.*;

import org.junit.Test;

public class containmostwaterTest {

	@Test
	public void test() {
		containmostwater test = new containmostwater();
		int[] height = {1,3,2,4,5,6,10,2};
		int ans = test.maxArea(height);
		assertEquals("must be", 15, ans);
	}

}
