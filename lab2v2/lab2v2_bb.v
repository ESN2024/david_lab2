
module lab2v2 (
	clk_clk,
	pio_0_external_connection_export,
	pio_1_external_connection_export,
	reset_reset_n);	

	input		clk_clk;
	input	[9:0]	pio_0_external_connection_export;
	output	[11:0]	pio_1_external_connection_export;
	input		reset_reset_n;
endmodule
