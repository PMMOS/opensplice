
package org.opensplice.dds.dcps;

/**
 * This interface is implemented by all DDS defined classes and holds the 
 * adress of the equivalent <code>gapi</code> object. The adress is stored as a 
 * <code>long</code> because the <code>gapi</code> can be compiled for any
 * platform using up to 64 bit adressing. 
 */
abstract public class SajSuperClass {
	
	/**
	 * The adress of the equivalent object in the <code>gapi</code> 
	 */
	private long gapiPeer = 0;
}
