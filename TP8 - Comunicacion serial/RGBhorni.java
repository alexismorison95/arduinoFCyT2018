package rgb;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import gnu.io.CommPortIdentifier;
import gnu.io.SerialPort;
import java.io.IOException;
import java.io.OutputStream;
import java.util.Enumeration;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;


public class RGBhorni extends JFrame {

	private JPanel contentPane;
	
	private OutputStream Output = null;
	SerialPort serialPort;
	private final String PORT_NAME = "COM11";
	private static final int TIME_OUT = 2000;
	private static final int DATA_RATE = 9600;


	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					RGBhorni frame = new RGBhorni();
					frame.setVisible(true);
					
					
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	
	public void ArduinoConnection() {
		CommPortIdentifier portId = null;
		Enumeration portEnum = CommPortIdentifier.getPortIdentifiers();
		while (portEnum.hasMoreElements()) {
			CommPortIdentifier currPortId = (CommPortIdentifier) portEnum.nextElement();
			
			if (PORT_NAME.equals(currPortId.getName())) {
				portId = currPortId;
				break;
			}
		}
		if (portId == null) {
			System.exit(ERROR);
			return;
		}

		try {
			serialPort = (SerialPort) portId.open(this.getClass().getName(), TIME_OUT);
			serialPort.setSerialPortParams(DATA_RATE,
			SerialPort.DATABITS_8,
			SerialPort.STOPBITS_1,
			SerialPort.PARITY_NONE);
			Output = serialPort.getOutputStream();
		} catch (Exception e) {
			//System.exit(ERROR);
			System.out.println("Error");
		}
	}
	
	private void EnviarDatos(String data) {
		try {
			Output.write(data.getBytes());
		} catch (IOException e) {
			System.exit(ERROR);
		}
	}

	/**
	 * Create the frame.
	 */
	public RGBhorni() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 884, 327);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JButton btnRojo = new JButton("rojo");
		btnRojo.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				EnviarDatos("1");
			}
		});
		btnRojo.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				
			}
		});
		btnRojo.setBounds(22, 13, 97, 25);
		contentPane.add(btnRojo);
		
		JButton btnVerde = new JButton("verde");
		btnVerde.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				EnviarDatos("3");
			}
		});
		btnVerde.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
			}
		});
		btnVerde.setBounds(22, 51, 97, 25);
		contentPane.add(btnVerde);
		
		JButton btnAzul = new JButton("azul");
		btnAzul.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				EnviarDatos("2");
			}
		});
		btnAzul.setBounds(22, 89, 97, 25);
		contentPane.add(btnAzul);
		
		JButton btnAmarillo = new JButton("amarillo");
		btnAmarillo.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				EnviarDatos("5");
			}
		});
		btnAmarillo.setBounds(22, 127, 97, 25);
		contentPane.add(btnAmarillo);
		
		JButton btnVioleta = new JButton("violeta");
		btnVioleta.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				EnviarDatos("4");
			}
		});
		btnVioleta.setBounds(22, 165, 97, 25);
		contentPane.add(btnVioleta);
		
		JButton btnCeleste = new JButton("celeste");
		btnCeleste.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				EnviarDatos("6");
			}
		});
		btnCeleste.setBounds(22, 203, 97, 25);
		contentPane.add(btnCeleste);
		
		JButton btnBlanco = new JButton("blanco");
		btnBlanco.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				EnviarDatos("7");
			}
		});
		btnBlanco.setBounds(22, 241, 97, 25);
		contentPane.add(btnBlanco);
		
		ArduinoConnection(); 
	}
}
