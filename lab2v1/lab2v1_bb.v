
module lab2v1 (
	clk_clk,
	reset_reset_n,
	pio_0_external_connection_export,
	pio_1_external_connection_export);	

	input		clk_clk;
	input		reset_reset_n;
	input	[9:0]	pio_0_external_connection_export;
	output	[3:0]	pio_1_external_connection_export;
endmodule
